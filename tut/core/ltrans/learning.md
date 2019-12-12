[Basic Linear Transformation](https://docs.opencv.org/master/d3/dc1/tutorial_basic_linear_transform.html)

### Pixel Transformation
- Brightness and contrast adjustment

g(x) = a.f(x) + b
a = contrast
b = brightness

### `saturate_cast()` function
We could have done 
`new_image.at<Vec3b>(y,x)[c] = a*image.at<Vec3b>(y,x)[c] + b;`

But this could have yielded values outside the character range. So we use:

`new_image.at<Vec3b>(y,x)[c] = saturate_cast<uchar>( a*image.at<Vec3b>(y,x)[c] + b);`


### optimized version of hand-coded:
`image.convertTo(new_image, -1, alpha, beta);`

```cpp
for( int y = 0; y < image.rows; y++ ) {
        for( int x = 0; x < image.cols; x++ ) {
            for( int c = 0; c < image.channels(); c++ ) {
                new_image.at<Vec3b>(y,x)[c] =
                  saturate_cast<uchar>( alpha*image.at<Vec3b>(y,x)[c] + beta );
            }
        }
    }

//saturate_cast > 255 -> 255, < 0 -> 0
```
