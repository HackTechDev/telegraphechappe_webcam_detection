#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

import cv2
import numpy as np
import glob
import json
import time

cap = cv2.VideoCapture(0)

cap.set(3,1280)
cap.set(4,960)

motionCounter = 0

ret, frame1 = cap.read()
ret, frame2 = cap.read()

print(frame1.shape)
while cap.isOpened():
    diff = cv2.absdiff(frame1, frame2)
    gray = cv2.cvtColor(diff, cv2.COLOR_BGR2GRAY)
    blur = cv2.GaussianBlur(gray, (5, 5), 0)
    _, thresh = cv2.threshold(blur, 50, 255, cv2.THRESH_BINARY)
    dilated = cv2.dilate(thresh, None, iterations = 3)
    contours, _ = cv2.findContours(dilated, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

    for contour in contours:
        (x, y, w, h) = cv2.boundingRect(contour)

        if cv2.contourArea(contour) < 900:
            continue
        cv2.rectangle(frame1, (x, y), (x + w, y + h), (0, 255, 0), 2)
        cv2.putText(frame1, "Status: {}".format('Movement'), (10, 20), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 3)
        #print("Log: Move detected " + str(contour))
        print("Log: Move detected ")
        print("Image matching #" + str(motionCounter))
        
        motionCounter = motionCounter + 1

    cv2.drawContours(frame1, contours, -1, (0, 255, 0), 2)

    cv2.imshow("feed", frame1)
    frame1 = frame2
    ret, frame2 = cap.read()

    if cv2.waitKey(40) == 100: # Key d
        print('Motion')
        cv2.imwrite('motion.jpg', frame1)
        img_rgb = cv2.imread('motion.jpg')
        img_gray = cv2.cvtColor(img_rgb, cv2.COLOR_BGR2GRAY)

        for f in glob.iglob("sign/*.jpg"):
            template = cv2.imread(f, 0)
            w, h = template.shape[::-1]

            res = cv2.matchTemplate(img_gray,template,cv2.TM_CCOEFF_NORMED)
            threshold = 0.7
            loc = np.where( res >= threshold)

            print(loc)

            flag = False
            for pt in zip(*loc[::-1]):
                if pt is not None:
                    flag = True
                    cv2.rectangle(img_rgb, pt, (pt[0] + w, pt[1] + h), (0, 255, 255), 2)
                    break

            if flag == True:
                print("log: " + f)
                cv2.imwrite('detected.jpg', img_rgb)

                pointPos = f.find('.')
                signalNumber = f[9:pointPos]     
                signal_dict = {"signal": signalNumber}
                path_json = 'signal.json'
                with open(path_json, 'w') as json_file:
                    json.dump(signal_dict, json_file)
                break                        


    if cv2.waitKey(40) == 27:
        break

cv2.destroyAllWindows()
cap.release()
