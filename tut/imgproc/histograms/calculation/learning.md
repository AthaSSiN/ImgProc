[Histogram calc](https://docs.opencv.org/master/d8/dbc/tutorial_histogram_calculation.html)

As in equalizaation, histogram data doesnt necesarliy have to be intensity variation only, it can be other data too!

Plotting histogram: involves splitting up of the values the histogram can take into divisions called bins 
dims: is the dimensions in which the histogram is being plotted.
range: the possible vals the histogram can take is called range.

To plot the histogram of BGR intensities in an image we do:

1. We declare a vector of BGR planes and split the source into the respective BGR values and store each one in the vector.
2. We declare the range of the histogram and initialize an array of floats as the histogramRnage with the firsts element being an array containing the range of the histogram.
3. we call the calcHist function with the following params: 
&bgr_planes[index] : The source array containing the indiv split channels
srcArrCount: The number of source arrays
dim: The channel to be measured (intensity only means 0)
Mat() : A mask that has been used
hist : the mat in which the hist is stored
dimCount: the hisotgram dimension count is stored here.
&histSize : The size of the histogram
&histRange: the range of vals the hist can take.
uniform : splits the bin into equal sizes
accumulate : histogram is cleared at the beginning

We'll need to normalize the values returned so that they fall in the range indicated by us.
> normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );

