[DFT](https://docs.opencv.org/master/d8/d01/tutorial_discrete_fourier_transform.html)

### Code explaination 

1. DFT works best when image dimensions are multiples of 2, 3 or 5, so we need to create a padded matrix of the correct dimensions
```cpp
    Mat padded;                            //expand input image to optimal size
    int m = getOptimalDFTSize( I.rows );
    int n = getOptimalDFTSize( I.cols ); // on the border add zero values
    copyMakeBorder(I, padded, 0, m - I.rows, 0, n - I.cols, BORDER_CONSTANT, Scalar::all(0)); //stores a bordered version of I in padded matrix, with pixels = 0
```

2. As the result of fourier transform has 2 components, and floats, so we need to expand our matrix to hold another(complex) channel:
```cpp
    Mat planes[] = {Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F)}; //typecasted padded from uchar to float, mde complex matrix of float init as 0 matrix
    Mat complexI;
    merge(planes, 2, complexI);  //creates complexI with 2 channels (the 2 cols of planes)
```

3. Perform DFT, and store magnitude:

```cpp
    dft(complexI, complexI); //store dft result in complexI
    split(complexI, planes); // planes[0] = Re(DFT(I), planes[1] = Im(DFT(I)) (splits channels)
    magnitude(planes[0], planes[1], planes[0]);// planes[0] = magnitude 
    //stores magnitude of first 2 args (sqrt(a^2 + b^2)) in the third arg
    Mat magI = planes[0];
```

4. As the ranges of the numbers is too large, we use the logarithmic scale and store each pixel value as Mi = log(1+Mi)
```cpp
    magI += Scalar::all(1);
    log(magI, magI);
```

5. Remove the extra borders and rearrange the matrix
```cpp
    // crop the spectrum, if it has an odd number of rows or columns
    magI = magI(Rect(0, 0, magI.cols & -2, magI.rows & -2));
    // rearrange the quadrants of Fourier image  so that the origin is at the image center
    int cx = magI.cols/2;
    int cy = magI.rows/2;
    Mat q0(magI, Rect(0, 0, cx, cy));   // Top-Left - Create a ROI per quadrant
    Mat q1(magI, Rect(cx, 0, cx, cy));  // Top-Right
    Mat q2(magI, Rect(0, cy, cx, cy));  // Bottom-Left
    Mat q3(magI, Rect(cx, cy, cx, cy)); // Bottom-Right
    Mat tmp;                           // swap quadrants (Top-Left with Bottom-Right)
    q0.copyTo(tmp);
    q3.copyTo(q0);
    tmp.copyTo(q3);
    q1.copyTo(tmp);                    // swap quadrant (Top-Right with Bottom-Left)
    q2.copyTo(q1);
    tmp.copyTo(q2);
```

6. Normalize for visualization. We now have the magnitudes, however this are still out of our image display range of zero to one. We normalize our values to this range using the cv::normalize() function.
```cpp
  normalize(magI, magI, 0, 1, NORM_MINMAX); // Transform the matrix with float values into a viewable image form (float between values 0 and 1).
```
