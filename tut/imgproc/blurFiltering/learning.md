[Filtering and blurring](https://docs.opencv.org/master/dc/dd3/tutorial_gausian_median_blur_bilateral_filter.html)

### FILTERS:

1. Normalized Box Filter:
This filter is the simplest of all! Each output pixel is the mean of its kernel neighbors ( all of them contribute with equal weights)

```cpp
for ( int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2 )
    {
        blur( src, dst, Size( i, i ), Point(-1,-1) );
    }
```
OpenCV offers the function blur() to perform smoothing with this filter. We specify 4 arguments (more details, check the Reference):
* src: Source image
* dst: Destination image
* Size( w, h ): Defines the size of the kernel to be used ( of width w pixels and height h pixels)
* Point(-1, -1): Indicates where the anchor point (the pixel evaluated) is located with respect to the neighborhood. If there is a negative value, then the center of the kernel is considered the anchor point.

2. Gaussian filter: kernel looks like normal bell curve
```cpp
for ( int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2 )
    {
        GaussianBlur( src, dst, Size( i, i ), 0, 0 );
    }
```
It is performed by the function GaussianBlur() : Here we use 4 arguments (more details, check the OpenCV reference):
* src: Source image
* dst: Destination image
* Size(w, h): The size of the kernel to be used (the neighbors to be considered). w and h have to be odd and positive numbers otherwise the size will be calculated using the σx and σy arguments.
* σx: The standard deviation in x. Writing 0 implies that σx is calculated using kernel size.
* σy: The standard deviation in y. Writing 0 implies that σy is calculated using kernel size.

3. Median filter: replaces pixel's value with median of neighbouring pixels
```cpp
    for ( int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2 )
    {
        medianBlur ( src, dst, i );
    }
```

i is the size of the kernel (square) and MUST BE ODD

4. Bilateral filter: in order to not smoothen out the whole pic, intesisty of pixels is also considered. Check [here](http://homepages.inf.ed.ac.uk/rbf/CVonline/LOCAL_COPIES/MANDUCHI1/Bilateral_Filtering.html)
```cpp
 for ( int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2 )
    {
        bilateralFilter ( src, dst, i, i*2, i/2 );
    }
```
Provided by OpenCV function bilateralFilter() We use 5 arguments:
* src: Source image
* dst: Destination image
* d: The diameter of each pixel neighborhood.
* σColor: Standard deviation in the color space.
* σSpace: Standard deviation in the coordinate space (in pixel terms)
