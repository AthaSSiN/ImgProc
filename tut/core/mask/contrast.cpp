#include<opencv2/opencv.hpp>
#include<iostream>
#include<opencv2/imgcodecs.hpp>
using namespace std;
using namespace cv;

void Sharpen(const Mat& myImage,Mat& Result);
int main( int argc, char* argv[])
{
    const char* filename = argc >=2 ? argv[1] : "ironman.jpg";
    Mat src, dst0, dst1;
    if (argc >= 3 && !strcmp("G", argv[2]))
        src = imread(  filename, 0);
    else
        src = imread( filename , 1);
    if (src.empty())
    {
        cerr << "Can't open image ["  << filename << "]" << endl;
        return -1;
    }
    namedWindow("Input", WINDOW_AUTOSIZE);
    namedWindow("Output", WINDOW_AUTOSIZE);
    imshow( "Input", src );

    Sharpen(src,dst0);
	imshow("Output", dst0);
    waitKey(0);
    return 0;
}

void Sharpen(const Mat& myImage,Mat& Result)
{
    CV_Assert(myImage.depth() == CV_8U);  // accept only uchar images
    const int nChannels = myImage.channels();
    Result.create(myImage.size(),myImage.type());
    for(int j = 1 ; j < myImage.rows-1; ++j)
    {
        const uchar* previous = myImage.ptr<uchar>(j - 1);
        const uchar* current  = myImage.ptr<uchar>(j    );
        const uchar* next     = myImage.ptr<uchar>(j + 1);
        uchar* output = Result.ptr<uchar>(j);
        for(int i= nChannels;i < nChannels*(myImage.cols-1); ++i)
        {
            *output++ = saturate_cast<uchar>(5*current[i]
                         -current[i-nChannels] - current[i+nChannels] - previous[i] - next[i]);
        }
    }
    Result.row(0).setTo(Scalar(0));
    Result.row(Result.rows-1).setTo(Scalar(0));
    Result.col(0).setTo(Scalar(0));
    Result.col(Result.cols-1).setTo(Scalar(0));
}
