[Canny detector](https://docs.opencv.org/master/da/d5c/tutorial_canny_detector.html)

The Canny Edge detector [35] was developed by John F. Canny in 1986. Also known to many as the optimal detector, the Canny algorithm aims to satisfy three main criteria:

1. Low error rate: Meaning a good detection of only existent edges.
2. Good localization: The distance between edge pixels detected and real edge pixels have to be minimized.
3. Minimal response: Only one detector response per edge.

### Steps

1. Filter out any noise. The Gaussian filter is used for this purpose.
Find the intensity gradient of the image. For this, we follow a procedure analogous to Sobel:
2. Apply a pair of convolution masks (in x and y directions, same as Sobel Masks)
3. Find the gradient strength and direction with:
G=G2x+G2y−−−−−−−√θ=arctan(GyGx)
* The direction is rounded to one of four possible angles (namely 0, 45, 90 or 135)
4. Non-maximum suppression is applied. This removes pixels that are not considered to be part of an edge. Hence, only thin lines (candidate edges) will remain.
5. Hysteresis: The final step. Canny does use two thresholds (upper and lower):
* If a pixel gradient is higher than the upper threshold, the pixel is accepted as an edge
* If a pixel gradient value is below the lower threshold, then it is rejected.
* If the pixel gradient is between the two thresholds, then it will be accepted only if it is connected to a pixel that is above the upper threshold.

__Canny recommended a upper:lower ratio between 2:1 and 3:1.__
