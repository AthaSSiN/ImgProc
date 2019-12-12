#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main( void )
{
   double a = 0.5; double b; double input;
   Mat src1, src2, dst;
   cout << " Simple Linear Blender " << endl;
   cout << "-----------------------" << endl;
   cout << "* Enter alpha [0.0-1.0]: ";
   cin >> input;
   // We use the alpha provided by the user if it is between 0 and 1
   if( input >= 0 && input <= 1 )
     { a = input; }
   //string im1,im2;
   //cin>>im1>>im2;
   src1 = imread( "../../ironman.jpg" );
   src2 = imread( "../../wall.jpg" );

   Rect r(0,0,1800,1000);
   if( src1.empty() ) { cout << "Error loading src1" << endl; return EXIT_FAILURE; }
   if( src2.empty() ) { cout << "Error loading src2" << endl; return EXIT_FAILURE; }
   src1 = src1(r);
   src2 = src2(r);
   b = ( 1.0 - a );
   addWeighted( src1, a, src2, b, 0.0, dst);
   imshow( "Linear Blend", dst );
   waitKey(0);
   return 0;
}
