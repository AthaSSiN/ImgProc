[Remapping](https://docs.opencv.org/master/d1/da0/tutorial_remap.html)

### Remapping

It is the process of taking pixels from one part of an image and locating them in another position of the image. Example flipping, rotating etc are implementations of remapping.

we use the remap function for this, which is:
remap(src, dst, mapping_function_for_x, mapping_function_for_y,  INTER_LINEAR, BORDER_CONSTANT);
