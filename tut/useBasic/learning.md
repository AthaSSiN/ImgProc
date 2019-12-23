https://docs.opencv.org/master/db/deb/tutorial_display_image.html
https://docs.opencv.org/master/db/d64/tutorial_load_save_image.html

to include all opencv headers, use #include <opencv2/opencv.hpp>

using namespace cv; using namespace std; is imp to make code short

### imread() function: 
loads image specified in first arg (imgName of argv[1]) and takes 2nd parameters : -1,0,1

-1 : load as is
0: load in grayscale
1: load in BGR

### display image 
using namedWindow( <windowName>, WINDOW_AUTOSIZE);
and then imshow(<windowName>, <matrixName>);

### convert image from one type to another (like BGR to grayscale) using cvtColor()
Mat grad_img
cvtColor( <originalMat>, <newMat>, COLOR_BGR2GRAY);

### save this new matrix by using imwrite()
imwrite("<path/to/file/fileName.format>", <newMat>);

### Move window to given coordinates:
`moveWindow( atom_window, 0, 200 );`
