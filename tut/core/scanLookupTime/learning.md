###Color Space Reduction:
for a BGR mat (0,255) each, there are 16million color combinations, working with all of them can make the program real slow
So we use a color reduction formula:
like vals 0-9 set as 0, 10-19 set as 10, and so on....
basically to use a specific divide setter use the code:

*******************************************
int divideWith = 10; // set default divider if not provided;

//our input format will be executable imgName divider (optional [G] for grayscale, otherwise BGR)

//so , set:

stringstream s; //used to convert text to int

s << argv[2];
if(s)
	s >> divideWith;

if(!divideWith)
{
	cout<<"NOT ALLOWED";
	return -1;
}

uchar table[256]; // lookup table
forf(256,i)
	table[i] = (uchar)(divideWith * (i/divideWith));

//we create this table  to avoid repeated multiply divides as they are costly

---------------------------------------------------

### Measuring runtime using getTickCount() [number of ticks since sys started] and getTickFrequency() [number of ticks/second]

****************************************************
double t = (double)getTickCount();
// do something ...
t = ((double)getTickCount() - t)/getTickFrequency();
cout << "Times passed in seconds: " << t << endl;

----------------------------------------------------


Now there are many ways to assign the new values to the orgiginal matrix, like making your own functions, but we use the inbuilt function LUT:

###LUT()

*****************************************************
Mat lookUp(1,256,CV_8U) // create lookup table of type matrix of 1 row, 256 cols, of unsigned char type

char *p = lookUp.prt();
forf(256,i)
	p[i] = table[i];

//now, convert from the lookup table

LUT(<inputMat>, lookUpTable, <outputMat>);

-----------------------------------------------------
