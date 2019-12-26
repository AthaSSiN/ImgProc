[The laplacian operator](https://docs.opencv.org/master/d5/db5/tutorial_laplace_operator.html)

The laplacian operator is used to find the second order derivative of 2 objects (such as images) as Laplace(f) = d2f/dx2 + d2f/dy2.
The laplacian operator internally calls the Sobel operator to find the double derivative and adds the individual second order derivatives (as we can otherwise find second order derivatives directly from sobel only)

It is again used similar to the sobel function in order to find the edges in an image
Laplacian ( src_gray, dst, ddepth, kernel_size, scale, delta, border_default)
