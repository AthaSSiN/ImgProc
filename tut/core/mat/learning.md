https://docs.opencv.org/master/d6/d6d/tutorial_mat_the_basic_image_container.html

### create an image reading object using Mat.
it has all the normal C++ OOP paradigms (copy contructor etc)

matrices made using copy constructors and assignments point to the same obj, any changes made to any one of them leads to a global change

code: ***************************************************

Mat A,C;	//creates header parts
A = imread(argv[1], IMREAD_COLOR);	//allocate matrix using a method

MatB(A); //using copy contructor
C = A; //Assignment operator

end of code: --------------------------------------------

##### for creating headers pointing to a specific mart of an image (for eg you need one matrix to take care of a small part of the image) you can define a header with a new set of boundaries

*********************************************

Mat D(A, Rect(10,10,100,100) ); //A rectangular range
Mat E = A(Range ::all(), Range(1,3)); // all rows and cols from 1 to 3

---------------------------------------------

#### memory is auto managed by openCV, chill for that

now, if you need to modify a matrix at a different place (such that the original marix is not changed)  you need to use clone() and copyTo()

**********************************************
Mat F = A.clone() // creaates new headers and puts img of A in them
Mat G;
A.copyTo(G);
----------------------------------------------


