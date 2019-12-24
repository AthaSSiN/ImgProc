[Make Borders](https://docs.opencv.org/4.2.0/dc/da3/tutorial_copyMakeBorder.html)

To make a border around an image , we use the copyMakeBorder function
> copyMakeBorder(src, dst, top, bottom, left, right, borderType, value)

Here:
1. top, bottom, left, right, specify (in order) the thickness of the border on each side (int).
2. borderType: 0 for a BORDER_CONSTANT, and 1 for BORDER_REPLICATE (border replicated from the pixel value at the edges of the image)
3. value : an array which contains the colors of the channels and is applied in case of borderType = 0.


