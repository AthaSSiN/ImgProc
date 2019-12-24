[Pyramid Scaling](https://docs.opencv.org/master/d4/d1f/tutorial_pyramids.html)

1. We can perform scaling up and down of images using pyrUp (to upscale) and pyrDown (to down scale) an image. 

There are two kinds of image pyramids, here we'll use the Gaussian pyramid, which downsamples (reduces the quality) of the image.

What it does? :

1. Imagine a pyramid as a set of layers, and the higher layer has a smaller size. 

2. Take the lengths of the layers as multiples of 2 (this function upscales and downscales in multiples of 2)

Every layer is numbered from bottom to top, so layer (i+1) (denoted as Gi+1 is smaller than layer i ( Gi).

3. To produce layer (i+1) in the Gaussian pyramid, we do the following:

	* Convolve Gi with a Gaussian kernel:
		| 1  4  6  4  1 |
		| 4  16 24 16 4 |
   	1/16	| 6  24 36 24 6 |
		| 4  16 24 16 4 |
		| 1  4  6  4  1 |
	* Remove every even-numbered row and column.
> You can easily notice that the resulting image will be exactly one-quarter the area of its predecessor. Iterating this process on the input image G0 (original image) produces the entire pyramid. Note that downscaling can only work as long as both the length and breadth remain divisible by 2.
> The procedure above was useful to downsample an image. What if we want to make it bigger?: columns filled with zeros ( 0)
1. First, upsize the image to twice the original in each dimension, with the new even rows and
2. Perform a convolution with the same kernel shown above (multiplied by 4) to approximate the values of the "missing pixels"
3. These two procedures (downsampling and upsampling as explained above) are implemented by the OpenCV functions pyrUp() and pyrDown().
