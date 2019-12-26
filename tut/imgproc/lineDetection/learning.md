[Line Detection](https://docs.opencv.org/master/d9/db0/tutorial_hough_lines.html)

The HoughLines formulae detect if two or more points lie in the same line or not by plotting the family of lines passing through each point in terms or r and theta and seeing if they intersect at a point or not. I they do, it means that they lie on the same straight line.

There are two HoughLine Transforms:

1. HoughLines(src, vector to store resulting lines, resolution of r (1), resolution of theta (CV_PI/180), threshold(minimum no. of intersections to detect a line), 0, 0)
Returns lines in (r,theta)

2. HoughLinesP(src, vector, 1, 1 degree, minIntersections -> 50, minPts -> 50 ,maxGap -> 10)
Returns lines in x and y coordinate

These functions are applied after canny edge detections for increased efficiency.


