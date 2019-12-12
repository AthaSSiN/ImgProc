[Image operations](https://docs.opencv.org/master/d5/d98/tutorial_mat_operations.html)

### I/O
* Load an image using `Mat img = imread(filename, -1/0/1);`
* Save an image using `imwrite(filename.ext, img);

### Basic ops with images
1. Accessing pixel intensity values

```cpp
//For BW images use
Scalar intensity = img.at<uchar>(Point(x,y));

//For BGR images (default format of imread);
Vec3b intensity = img.at<Vec3b>(y,x); //as y is rows and x is cols!!
uchar blue = instensity.val[0];
uchar green = intensity.val[1];
uchar red = intensity.val[2];

//replace uchar with float and Vec3b with Vec3f for floating-point imgs

img.at<uchar>(y,x) = 128; //changes pix intensity at x,y to 128
``` 

2. Mem mgmnt and ref counting

```cpp
//convert from one matrix type to another using reshape function
vector<Point3f> points;
// ..... fill vector
Mat pointsmat = Mat(points).reshape(1); //makes 32FC1 mat with 3 cols not 32FC3 mat with 1 col

//make a copy with a different address:
Mat img1 = img.clone();

//pass empty matrices to functions so that they contained returned images
```

3. Primitive ops

```cpp
//create a black img:
img = Scalar(0);

//select a specific region:
Rect r(10,10,100,100);
Mat small = img(r);

//convert color to bw
cvtColor(img, grey, COLOR_BGR2GRAY);

//change img type here 8UC1 to 32FC1 idk if can't change channel numbers?
src.convertTo(dst, CV_32F);
```
