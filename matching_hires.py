#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

import cv2
import numpy as np


#img_rgb = cv2.imread('matching_hires/webcam_hires.jpg')
img_rgb = cv2.imread('motion.jpg')
img_gray = cv2.cvtColor(img_rgb, cv2.COLOR_BGR2GRAY)

template = cv2.imread('matching_hires/sign1.jpg',0)
w, h = template.shape[::-1]

res = cv2.matchTemplate(img_gray,template,cv2.TM_CCOEFF_NORMED)
threshold = 0.8
loc = np.where( res >= threshold)

print(loc)

for pt in zip(*loc[::-1]):
    cv2.rectangle(img_rgb, pt, (pt[0] + w, pt[1] + h), (0,255,255), 2)

cv2.imwrite('matching_hires/detected.jpg',img_rgb)
cv2.imshow('Detected', img_rgb)
