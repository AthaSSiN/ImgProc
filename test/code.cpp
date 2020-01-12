#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"
#include <iostream>
#include <vector>
using namespace cv;
using namespace std;

int maxContourId(vector <vector<Point>> contours) {
    double maxArea = 0;
    int maxAreaContourId = -1;
    for (int j = 0; j < contours.size(); j++) {
        double newArea = contourArea(contours.at(j));
        if (newArea > maxArea) {
            maxArea = newArea;
            maxAreaContourId = j;
        } 
    } 
    return maxAreaContourId;
}
int main(int argc, char* argv[])
{
    VideoCapture cap(argc > 1 ? atoi(argv[1]) : 0);
    namedWindow("Actual video");
    namedWindow("Detection");
    Mat invid, frame, frame_HSV, res, framecol;
    while (true) {
        cap >> frame;
        if(frame.empty())
        {
            break;
        }
        // Convert from BGR to HSV colorspace
        cvtColor(frame, frame_HSV, COLOR_BGR2HSV);
	invid = frame.clone();
        // Detect the object based on HSV Range Values
        inRange(frame_HSV, Scalar(29,86,6), Scalar(64,255,255), res);
        
	cvtColor(res, framecol, COLOR_GRAY2BGR);
	vector<vector<Point> > contours;
   	
	medianBlur(res, res, 3);
    	findContours( res, contours, RETR_TREE, CHAIN_APPROX_SIMPLE );
	int i = maxContourId(contours);	
	vector<Point> ans;
	Point2f center;
	float radius;
        approxPolyDP( contours[i], ans, 10, true);
	minEnclosingCircle(ans, center, radius);
        if(radius>5)
	{
        	circle( invid, center, 1, Scalar(0,0,255), 3, LINE_AA);
        	circle( framecol, center, 1, Scalar(0,0,255), 3, LINE_AA);
	
        	circle( invid, center, radius, Scalar(0,0,255), 3, LINE_AA);
    		circle( framecol, center, radius, Scalar(0,0,255), 3, LINE_AA);
	}
        imshow("Actual video", frame);
        imshow("Detection", framecol);
	imshow("inVideo", invid);
        char key = (char) waitKey(30);
        if (key == 'q' || key == 27)
        {
            break;
        }
    }
    return 0;
}
