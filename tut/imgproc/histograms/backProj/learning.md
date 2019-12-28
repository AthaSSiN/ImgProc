[Back Projection](https://docs.opencv.org/master/da/d7f/tutorial_back_projection.html)

Back Projection is a way of recording how well the pixels of a given image fit the distribution of pixels in a histogram model.
To make it simpler: For Back Projection, you calculate the histogram model of a feature and then use it to find this feature in an image.
Application example: If you have a histogram of flesh color (say, a Hue-Saturation histogram ), then you can use it to find flesh color areas in an image:

What the code does:
1. Transform the image into HSV format
2. next use Mat.create to create another matrix of the same dimensions as the previous mat. Then use mix channels o set how to copy the channels from the original image to the created mat.
> maxChannels (&orig, 1 [no of source arrs], &fin[dest arr],1 [no of dest arrs], ch [] = {0,0} [shows mapping between the indices], 1 [no of index pairsin ch]);

3. Next, calc he hist and normalize it to the range [0,255]
4. calcBackProject(&fin [in the prev one, source this time], 1 [no. of source images], 0 [list of channels to compute backproj], hist [input hist], backproj [dest], &ranges [ranges], 1 [scale], true [uniform]);
