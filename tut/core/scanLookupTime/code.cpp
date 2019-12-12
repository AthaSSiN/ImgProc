#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main( int argc, char* argv[])
{
	if( argc < 3)
	{
		cout << "Less params\n";
		return -1;
	}

	Mat I,J;
	
	if (argc == 4 && !strcmp(argv[3], "G") )
		I = imread(argv[1], 0);
	else
		I = imread(argv[1], 1);

	if (I.empty())
	{
		cout << "The image couldn't be loaded \n";
		return -1;
	}

	int div = 0;
	stringstream s;
	s << argv[2];
	s >> div;

	if(!s || !div)
	{
		cout<<"Can't divide with zero \n";
		return -1;
	}

	uchar table[256];
	for (int i = 0; i < 256; ++i)
		table[i] = (uchar)(div*(i/div));


	Mat lookUp(1, 256, CV_8U);
	uchar* p = lookUp.ptr();
	for( int i = 0; i < 256; ++i)
			p[i] = table[i];

	LUT(I, lookUp, J);

	namedWindow("orig", WINDOW_AUTOSIZE);
	namedWindow("new", WINDOW_AUTOSIZE);

	imshow("orig", I);
	imshow("new", J);

	waitKey(0);

	return 0;
}
