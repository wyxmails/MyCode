/*
 Problem Statement
     
 Onise likes to play with paper and paint. He has a piece of paper with dimensions width x height. He does the following steps with the paper:
 Fold the paper along the line x = xfold (the left side of the paper is folded over the right side).
 Divide the paper vertically into cnt+1 equal sections. Then, cnt times, take the topmost section and fold it over the section below it.
 Paint a rectangle with the lower-left corner at (x1, y1) and the upper-right corner at (x2, y2). Note that (0, 0) is now the lower-left corner of the paper in its current folded state, not its original state. The paint will seep through all the layers of the folded paper. See the image below for clarification.
 Unfold the paper.
 For example, let's say Onise has a piece of paper that is 5 x 6. He performs the described steps where xfold is 2, cnt is 2, and the coordinates of the painted rectangle's corners are (1, 1) and (3, 2). The following will happen (note that the paper starts out blue in the images and gets painted white):
                 
    You are given ints width and height, and ints xfold, cnt, x1, y1, x2 and y2. Return the total area of of the paper that is not covered in paint after Onise is done.
	Definition
	    
Class:
PaperAndPaintEasy
Method:
computeArea
Parameters:
int, int, int, int, int, int, int, int
Returns:
long long
Method signature:
long long computeArea(int width, int height, int xfold, int cnt, int x1, int y1, int x2, int y2)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Constraints
-
width and height will be between 1 and 10^9, inclusive.
-
xfold will be between 0 and width, inclusive.
-
cnt will be between 0 and 1000, inclusive.
-
cnt+1 will be a divisor of height.
-
0 <= x1 < x2 <= max(xfold, width-xfold) and 0 <= y1 < y2 <= height/(cnt+1).
Examples
0)

    
5
6
2
2
1
1
3
2
Returns: 21
The example from the problem statement.
1)

    
3
13
1
0
1
8
2
12
Returns: 35

2)

    
12
12
7
3
3
1
6
2
Returns: 124

3)

    
4
5
4
0
0
0
1
1
Returns: 19

4)

    
4
8
4
3
0
1
2
2
Returns: 24

5)

    
4
8
3
0
1
1
3
2
Returns: 30

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
using namespace std;

class PaperAndPaintEasy{
public:
long long computeArea(int width, int height, int xfold, int cnt, int x1, int y1, int x2, int y2);
};

long long PaperAndPaintEasy::computeArea(int width, int height, int xfold, int cnt, int x1, int y1, int x2, int y2){
	long long two_layer_rim = min(width-xfold,xfold);
	long long y_lower = max(y1,0);
	long long y_higher = min(height/(cnt+1),y2);
	long long x_left = x1;
	long long x_right = x2;
	long long res;
	long long cnt_p = cnt+1;
	if(two_layer_rim<x1){
		res = (x_right-x_left)*(y_higher-y_lower)*cnt_p;
	}else if(two_layer_rim>x2)
		res = (x_right-x_left)*(y_higher-y_lower)*cnt_p*2;
	else{
		long long left_part = (two_layer_rim-x_left)*(y_higher-y_lower)*cnt_p*2;
		long long right_part = (x_right-two_layer_rim)*(y_higher-y_lower)*cnt_p;
		res = left_part+right_part;
	}
	res = (long long)width*(long long)height-res;
	return res;
}
