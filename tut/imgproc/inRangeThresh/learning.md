[inRange threshold](https://docs.opencv.org/master/da/d97/tutorial_threshold_inRange.html)

This is same as the threshold function, just that we can choose a pixel range of values that we require, using hue,sat,lum

inRange(src,lowerBound, upperBound, dst)
It checks if the elements of array src lie between the same indexed elements of lowerBound and upperBound. If this is true, then dst is set as 255, otherwise set as 0.


