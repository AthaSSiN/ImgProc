#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
using namespace cv;
void update_map( int &ind, Mat &map_x, Mat &map_y );
int main(int argc, const char** argv)
{
    CommandLineParser parser(argc, argv, "{@image |../../inna.jpg|input image name}");
    std::string filename = parser.get<std::string>(0);
    Mat src = imread( filename, IMREAD_COLOR );
    if (src.empty())
    {
        std::cout << "Cannot read image: " << filename << std::endl;
        return -1;
    }
    Mat dst(src.size(), src.type());
    Mat map_x(src.size(), CV_32FC1);
    Mat map_y(src.size(), CV_32FC1);
    const char* remap_window = "Remap demo";
    namedWindow( remap_window, WINDOW_AUTOSIZE );
    int ind = 0;
    for(;;)
    {
        update_map(ind, map_x, map_y);
        remap( src, dst, map_x, map_y, INTER_LINEAR, BORDER_CONSTANT, Scalar(0, 0, 0) );
        imshow( remap_window, dst );
        char c = (char)waitKey( 1000 );
        if( c == 27 )
        {
            break;
        }
    }
    return 0;
}
void update_map( int &ind, Mat &map_x, Mat &map_y )
{
    for( int i = 0; i < map_x.rows; i++ )
    {
        for( int j = 0; j < map_x.cols; j++ )
        {
            switch( ind )
            {
            case 0: // Shrink to center and make the rest border
                if( j > map_x.cols*0.25 && j < map_x.cols*0.75 && i > map_x.rows*0.25 && i < map_x.rows*0.75 )
                {
                    map_x.at<float>(i, j) = 2*( j - map_x.cols*0.25f ) + 0.5f;
                    map_y.at<float>(i, j) = 2*( i - map_x.rows*0.25f ) + 0.5f;
                }
                
                {
                    map_x.at<float>(i, j) = 0;
                    map_y.at<float>(i, j) = 0;
                }
                break;
            case 1: //upside down
                map_x.at<float>(i, j) = (float)j;
                map_y.at<float>(i, j) = (float)(map_x.rows - i);
                break;
            case 2: // flip
                map_x.at<float>(i, j) = (float)(map_x.cols - j);
                map_y.at<float>(i, j) = (float)i;
                break;
            case 3: // flip and rotate
                map_x.at<float>(i, j) = (float)(map_x.cols - j);
                map_y.at<float>(i, j) = (float)(map_x.rows - i);
                break;
            default:
                break;
            } // end of switch
        }
    }
    ind = (ind+1) % 4;
}
