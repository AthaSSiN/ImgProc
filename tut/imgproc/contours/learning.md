[Finding and making contours](https://docs.opencv.org/master/df/d0d/tutorial_find_contours.html)

The find and make contours are use to make the outlines of the images.
It is applied to the canny output of an image.

The contours are stored in a vector of points and are then plotted one by one.

findContours	(	InputArray 	image,
			OutputArrayOfArrays 	contours,
			OutputArray 	hierarchy,
			int 	mode,
			int 	method,
			Point 	offset = Point() 
		);

image: is an 8bit b/w image.
contours: detected contours, the contour is stored as a vector of points
hieracrchy: optional output vector
mode: contour Retrieval method : RETR_TREE
method : Contour approx method : CHAIN_APPROX_SIMPLE
offset : offset by which the whole contour has to be shifted	


