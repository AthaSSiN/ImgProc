[Histogram Comparison](https://docs.opencv.org/master/d8/dc8/tutorial_histogram_comparison.html)

Histograms can be comapred in openCV using the function compareHist.
1.  first we have to choose a metric ( d(H1,H2)) to express how well both histograms match.
The 4 different methods the function provides to compare hists are:
0. CV_COMP_CORREL (correlation)
1. CV_COMP_CHISQR (chi square)
2. CV_COMP_INTERSECT (intersection)
3. CV_COMP_BHATTACHARYA (Bhattacharya distance)

We use 
compareHist(hist1, hist2, compare_method)

