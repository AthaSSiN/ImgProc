[Hor Vert Line Detection](https://docs.opencv.org/master/dd/dd7/tutorial_morph_lines_detection.html)

We use our basic morphological operations and structuring element making in order to solve our problem in this case

making linear structuring elements can help us with this task.

1. First, we convert our input image to grayscale (single channel)
2. Next, we convert our grayscale image to a binary image (of 0 and 255 value only), using the adaptiveThreshlod(src,dst,maxVal,adaptiveMethod, tresholdType,blocksize,c) function.

The blocksize is used to define the kernel size, whose average pixel value = 0 (or gaussian mean = 1) is taken to calculate T(x,y)

for adaptiveMethod = 
THRESH_BINARY= 0 = dst(x,y)={maxValue if src(x,y)>T(x,y), 0 otherwise

THRESH_BINARY_INV = 1 = dst(x,y)={0 if src(x,y)>T(x,y), maxvalue otherwise

c is the const subtracted from the weighted mean.

We take the binary inverse in this step.

3. Next, we set a size for our expected horizontal and vertical lines, lenth:
int hor_size = hor.cols/30 (where hor = bw.clone())

4. Next, we make our linear structuring elements!

5. We close, i.e erode, then dilate our image, and as the structuring element is only one pixel thick, the linear parts of the picture are preserved, while rest everything gets closed into a black background.


