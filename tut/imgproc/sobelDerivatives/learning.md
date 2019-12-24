[Sobel Derivatives](https://docs.opencv.org/master/d2/d2c/tutorial_sobel_derivatives.html)

The best way to identify the edges (sudden changes in pixel values) in an image, like in maths, is to take the derivative (the change of the pixel values in the neighbourhood of the given pixel. Computing the actual derivative is a tough problem, so openCV uses the sobel function to calculate approx values of the derivative.

##  SOBEL
The function works int the following way:
1. We calculate 2 derivatives (changes) using matrices:
	* Horizontal Changes: convolve I with a kernel Gx of odd size:
			[ -1  0  +1 ]
		Gx =    [ -2  0  +2 ]
			[ -1  0  +1 ]
	* Vertical Changes : convolve I with Gy of odd size:
			[ -1  0  +1 ](T)
		Gy =    [ -2  0  +2 ]
			[ -1  0  +1 ]

The function is Sobel(src, dst, ddepth, order_x, order_y, kernelSize = 3, scale= 1, delta = 0, borderType = 0);

ddepth : output image depth
kernelSize = 1,3,5,7 only
scale : scaling the computed derivative values by a given amount
delta: optional change to be added to a derivative value

2. We calculate G = sqrt(Gx^2 + Gy^2) or sometimes G = |Gx| + |Gy|
3. for a kernel size of 3, we use scharr function which produces more accurate results that sobel function. It uses:
			[  -3  0  +3  ]
		Gx =    [ -10  0  +10 ]
			[  -3  0  +3  ]
		Gy =    Gx(T)

Scharr has the same parameter types and orders, except the kernelSize (which is 3 in this case permanently)
> We use these methods after converting the images to grayscale for quicker computations

