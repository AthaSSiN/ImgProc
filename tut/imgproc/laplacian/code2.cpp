//code to compare laplacian and sobel and second order sobel sum

#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main( int argc, char** argv )
{
  Mat image,src, src_gray;
  Mat grad;

  int ksize = 1;
  int scale = 1;
  int delta = 0;
  int ddepth = CV_16S; // = 3
  // As usual we load our source image (src)
  image = imread( "../../inna.jpg", IMREAD_COLOR ); // Load an image
  // Check if image is loaded fine
  for (;;)
  {
    // Remove noise by blurring with a Gaussian filter ( kernel size = 3 )
    GaussianBlur(image, src, Size(3, 3), 0, 0, BORDER_DEFAULT);
    // Convert the image to grayscale
    cvtColor(src, src_gray, COLOR_BGR2GRAY);
    Mat grad_x, grad_y;
    Mat abs_grad_x, abs_grad_y;
    Sobel(src_gray, grad_x, ddepth, 2, 0, ksize, scale, delta, BORDER_DEFAULT);
    Sobel(src_gray, grad_y, ddepth, 0, 2, ksize, scale, delta, BORDER_DEFAULT);
    // converting back to CV_8U
    convertScaleAbs(grad_x, abs_grad_x);
    convertScaleAbs(grad_y, abs_grad_y);
    addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad);
    imshow("ORIGINAL SOBEL2", image);
    imshow("WHITE SOBEL2", grad);
    bitwise_not(grad,grad);
    imshow("SKETCH", grad);
    Mat dst;
    Laplacian(src_gray, dst, ddepth, ksize, scale, delta, BORDER_DEFAULT);
    imshow("BLACK LAPLACE", dst);
    bitwise_not(dst,dst);
    imshow("OUT LAPLACE", dst);
    char key = (char)waitKey(0);
    if(key == 27)
    {
      return EXIT_SUCCESS;
    }
    if (key == 'k' || key == 'K')
    {
      ksize = ksize < 30 ? ksize+2 : -1;
    }
    if (key == 's' || key == 'S')
    {
      scale++;
    }
    if (key == 'd' || key == 'D')
    {
      delta++;
    }
    if (key == 'r' || key == 'R')
    {
      scale =  1;
      ksize =  1;
      delta =  0;
    }
  }
  return EXIT_SUCCESS;
}
