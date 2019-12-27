[Histogram Equalization](https://docs.opencv.org/master/d4/d1b/tutorial_histogram_equalization.html)

### Histograms

Histograms graphically represent the intensity distribution of an image, quantifying the number of pixels for each intensity value recorded.

### Histogram Equalization

This tries to improve the contrast of an image by spreading out the histogram distribution in order to spread the intensities across a larger number of pixels. It sort of widens the histogram, without changing the max intensities. It populates the underly populated intensities.

the function equalizeHist(src,dst, COLOR_BGR2GRAY) does just that and we use it to adjust the contrast of an image.
