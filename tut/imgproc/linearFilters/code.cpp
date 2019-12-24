#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;
int main ( int argc, char** argv )
{
    // Declare variables
    Mat src, dst;
    Mat kernel;
    Point anchor;
    double delta;
    int ddepth;
    int kernel_height, kernel_width;
    const char* window_name = "filter2D Demo";

    // Loads an image
    src = imread( "../../img.png", IMREAD_COLOR ); // Load an image
    // Initialize arguments for the filter
    anchor = Point( -1, -1 );
    delta = 0;
    ddepth = -1;
    // Loop - Will filter the image with different kernel sizes each 0.5 seconds
    int ind = 0;
    for(;;)
    {
        // Update kernel size for a normalized box filter
        kernel_width = 3 + 2*( ind%5 );
	kernel_height = 3 + 2*(ind%10);
        kernel = Mat::ones( kernel_width, kernel_height, CV_32F )/ (float)(kernel_width*kernel_height);
        // Apply filter
        filter2D(src, dst, ddepth , kernel, anchor, delta, BORDER_DEFAULT );
        imshow( window_name, dst );
        char c = (char)waitKey(0);
        // Press 'ESC' to exit the program
        if( c == 27 )
        { break; }
        ind++;
    }
    return EXIT_SUCCESS;
}
