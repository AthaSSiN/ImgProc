[Linear Filters](https://docs.opencv.org/master/d4/dbd/tutorial_filter_2d.html)

We use the filter2D function in order to apply a given kernel with some properties to each pixel in an image. In the range of the elements , the elements of the image are multiplied with the values in the kernel, added together and replaced into the anchor point (usually the element at the center of the kernel). 

After setting the kernel, we can generate the filter by using the function filter2D() :
> // Apply filter
> filter2D(src, dst, ddepth , kernel, anchor, delta, BORDER_DEFAULT );

The arguments denote:
* src: Source image
* dst: Destination image
* ddepth: The depth of dst. A negative value (such as −1) indicates that the depth is the same as the source.
* kernel: The kernel to be scanned through the image
* anchor: The position of the anchor relative to its kernel. The location Point(-1, -1) indicates the center by default.
* delta: A value to be added to each pixel during the correlation. By default it is 0
* BORDER_DEFAULT: We let this value by default 
