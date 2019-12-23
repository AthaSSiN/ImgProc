[Basic Drawing](https://docs.opencv.org/master/d3/d96/tutorial_basic_geometric_drawing.html)

1. Point:
`Point pt = Point(10, 8);`

2. Setting colors: `Scalar(a,b,c);`

3. Make a shape filled using FILLED keyword after mentioning the color, or passing thickness parameter as -1.

4. Function to create a line:
```cpp
void MyLine( Mat img, Point start, Point end )
{
  int thickness = 2;
  int lineType = LINE_8;
  line( img,
    start,
    end,
    Scalar( 0, 0, 0 ),
    thickness,
    lineType );
}
```
As we can see, MyLine just call the function line() , which does the following:
* Draw a line from Point start to Point end
* The line is displayed in the image img
* The line color is defined by ( 0, 0, 0 ) which is the RGB value correspondent to Black
* The line thickness is set to thickness (in this case 2)
* The line is a 8-connected one (lineType = 8)

5. Function to create an ellipse:
```cpp
void MyEllipse( Mat img, double angle )
{
  int thickness = 2;
  int lineType = 8;
  ellipse( img,
       Point( w/2, w/2 ),
       Size( w/4, w/16 ),
       angle,
       0,
       360,
       Scalar( 255, 0, 0 ),
       thickness,
       lineType );
}
```
From the code above, we can observe that the function ellipse() draws an ellipse such that:
* The ellipse is displayed in the image img
* The ellipse center is located in the point (w/2, w/2) and is enclosed in a box of size (w/4, w/16)
* The ellipse is rotated angle degrees
* The ellipse extends an arc between 0 and 360 degrees
* The color of the figure will be ( 255, 0, 0 ) which means blue in BGR value.
* The ellipse's thickness is 2.

6. Create a filled circle:
```cpp
void MyFilledCircle( Mat img, Point center )
{
  circle( img,
      center,
      w/32,
      Scalar( 0, 0, 255 ),
      FILLED, // or use thickness = -1
      LINE_8 );
}
```
we can observe that circle receives as arguments:
* The image where the circle will be displayed (img)
* The center of the circle denoted as the point center
* The radius of the circle: w/32
* The color of the circle: ( 0, 0, 255 ) which means Red in BGR
* Since thickness = -1, the circle will be drawn filled.

7. Make a filled polygon : make a 2D array of points, Point polyg[1][20], set each element of the array to some point using the Point class constructor. Then

```cpp
const Point* ppt[1] = { plyg[0] };
  int npt[] = { 20 };
  fillPoly( img,
        ppt,
        npt,
        1,
        Scalar( 255, 255, 255 ),
        LINE_8 );
}
```

We can draw unfilled polygon using polylines and same args.

8. Make a rectangle using:
```cpp
rectangle( rook_image,
         Point( 0, 7*w/8 ),
         Point( w, w),
         Scalar( 0, 255, 255 ),
         thickness,
         LINE_8 );
//built straight from constructor
``` 
