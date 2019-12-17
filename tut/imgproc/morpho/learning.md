Opening : Useful for removing small and bright objs
	open(img) = dilate(erode(img))

Closing : Useful for removing small dark objs
	close(img) = erode(dilate(img))

Morphological gradient : useful for finding out the outline of objs
	morphgrad(img) = dilate(img) - erode(img)

top hat : difference b/w input img and opening 
	tophat(img) = img - open(img)

black hat : difference b/w closing and img
	blackhat(img) = close(img) - img
