#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

import numpy as np
import cv2
import glob


cap = cv2.VideoCapture(0)
overlay = cv2.imread('calibration/calibration.jpg')

cap.set(3,640)
cap.set(4,480)


while True:
    ret, img_rgb = cap.read()


    img_rgb = cv2.addWeighted(img_rgb, 0.4, overlay, 0.1, 0)
    cv2.imshow('Calibration',img_rgb)

    k = cv2.waitKey(30) & 0xff
    if k == 27:
        break

cap.release()
cv2.destroyAllWindows()
