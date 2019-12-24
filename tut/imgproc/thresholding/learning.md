[Basic thresh](https://docs.opencv.org/master/db/d8e/tutorial_threshold.html)

The difference between this and adaptive thresh used in the horizontal and vertical line extraction exercise is that we can chose a smaller kernel in adaptiveThresh while in this, the comparison is pixel wise.

1. Threshold Binary = 0
This thresholding operation can be expressed as:

dst(x,y)={maxVal0if src(x,y)>threshotherwise
So, if the intensity of the pixel src(x,y) is higher than thresh, then the new pixel intensity is set to a MaxVal. Otherwise, the pixels are set to 0.

2. Threshold Binary, Inverted = 1
This thresholding operation can be expressed as:

dst(x,y)={0maxValif src(x,y)>threshotherwise
If the intensity of the pixel src(x,y) is higher than thresh, then the new pixel intensity is set to a 0. Otherwise, it is set to MaxVal.

3. Truncate = 2
This thresholding operation can be expressed as:

dst(x,y)={thresholdsrc(x,y)if src(x,y)>threshotherwise
The maximum intensity value for the pixels is thresh, if src(x,y) is greater, then its value is truncated. See figure below:

4. Threshold to Zero = 3
This operation can be expressed as:

dst(x,y)={src(x,y)0if src(x,y)>threshotherwise
If src(x,y) is lower than thresh, the new pixel value will be set to 0.

5. Threshold to Zero, Inverted = 4
This operation can be expressed as:

dst(x,y)={0src(x,y)if src(x,y)>threshotherwise
If src(x,y) is greater than thresh, the new pixel value will be set to 0.
