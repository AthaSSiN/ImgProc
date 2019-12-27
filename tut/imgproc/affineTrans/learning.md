[Warp affine and rotation matrices](https://docs.opencv.org/master/d4/d61/tutorial_warp_affine.html)

### Affine Transformation

* A transformation that can be expressed in the form of a matrix multiplication (linear transformation) followed by a vector addition is an affine transformation.
* Hence, it can be used t express Rotations, Translations and Scale Operations

An affine transformation is represented using a 2 x 2 mat A and a 2 x 1 column mat B such that the transformation of a vector X into Y is represented as : T = A.X + B

This can be written as T = M.X^T where M is a matrix with elements of A in first 2 cols and B in the next two cols, while X contains the vector X and 1 ( to acomodate the scalar in the vector multiplication. ).

This is a problem of having 6 unknowns and we basically need 6 eqns (3 transformations) to find the affine transformation.

Steps:
1. We first make an array of 3 initial points and another array of the final location of the three points (note that they shouldn't come out to be linearly independent!! ).

2. Next get the warp matrix using the function :
> Mat warpmat = getAffineTransform(srcPoints, dstPoints);

3. apply the affine transformation to the input images using the matrix found above.
> warpAffine(src, dst, warpmat, src.size());

Next, steps to rotate a matrix using ltrans:
1. Fix a point as the centre of the rot mat (take it as the center of the image);
define angle if rotation and the amount by which to scale the image.
2. generate a rotation matrix using
> getRotationMatrix2D(center, angle, scale);
3. again apply warpAffine to it!
