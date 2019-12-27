[Circle detection](https://docs.opencv.org/master/d4/d70/tutorial_hough_circle.html)

The HoughCircles function is used to detect circles within an image.

The function is:
HoughCircles(inImg, outImg, detection_method [use HOUGH_GRADIENT], dp, minDist [b/w centers of detected circles], highThresh (higher thresh passed to cannyEdge), param2 [figure out, smaller is more false circles], minRadius, maxRadius [ 0 to use max image dimension, -1 to plot only the centres] )

It auto implements canny edge detection

dp: Inverse ratio of the accumulator resolution to the image resolution. For example, if dp=1 , the accumulator has the same resolution as the input image. If dp=2 , the accumulator has half as big width and height.
