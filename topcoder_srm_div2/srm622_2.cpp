/*
 Problem Statement
     
 Today is Fox Ciel's birthday. You want to give her a box of candies as a present.  You have candies of several different types. You are given a vector <int> candyCounts. Each element of candyCounts is the number of candies of one particular type.  For each non-negative integer i, you have an unlimited supply of boxes with volume 2^i. That is, you have boxes with volume 1, 2, 4, 8, and so on.  You are going to pack the candies into boxes. Each type of candies has to be packed into a single box, and you have to use different boxes for different types of candy. The volume of a box must be greater than or equal to the number of candies it contains.  Once you have each type of candies in a box, you want to pack those boxes into larger boxes, until only one box remains. You can only pack two boxes at a time. That is, you can take any two boxes you currently have, get a new box, and put the two old boxes into the new box. This is possible if and only if the volume of the new box is greater than or equal to the sum of volumes of the two old boxes. You always get to choose which two boxes you want to pack together, and how large the new box should be.  To summarize:
 First, you will pack all the candies into boxes.
 Then, you will pack all those boxes into larger boxes, until you are left with a single box that contains everything.
  Compute and return the smallest possible volume of the box obtained at the end of packing.
  Definition
      
Class:
BoxesDiv2
Method:
findSize
Parameters:
vector <int>
Returns:
int
Method signature:
int findSize(vector <int> candyCounts)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Notes
-
You may assume that the return value always fits into a signed 32-bit integer variable.
Constraints
-
candyCounts will contain between 1 and 100 elements, inclusive.
-
Each element of candyCounts will be between 1 and 1000, inclusive.
Examples
0)

    
{8,8}
Returns: 16
First, you pack each type of candies into a box with volume 8. Then, you pack the two boxes into a single box with volume 16.
1)

    
{5,6}
Returns: 16
Even though you have fewer candies than in Example 0, you still have to use boxes with volume 8 (or more) to store them.
2)

    
{1,7}
Returns: 16
Now you could pack the 1 candy into a smaller box, but it will not help: you still have to use a box with volume 16 to store the two boxes with candies.
3)

    
{1,1,13,1,1}
Returns: 32

4)

    
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32}
Returns: 1024

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

class BoxesDiv2{
public:
int findSize(vector <int> candyCounts);
};

int BoxesDiv2::findSize(vector <int> candyCounts){
	int n = candyCounts.size();
	sort(candyCounts.begin(),candyCounts.end());
	int p=0;
	vector<int> mark(50,0);
	for(int i=0;i<n;++i){
		if(candyCounts[i]>pow(2,p))
		while(pow(2,p)<candyCounts[i]) p++;
		mark[p]++;
	}
	int carr=0;
	for(int i=0;i<50;++i){
		if(mark[i]==0) continue;
		if(carr){
			mark[i]++;
			carr = 0;
		}
		mark[i+1] += mark[i]/2;
		if(mark[i]%2) carr = 1;
	}
	for(int i=49;i>=0;--i)
		if(mark[i]!=0){
			p=i;
			break;
		}
	return pow(2,p);
}

int main(){
	//int arr[] = {943, 828, 437, 392, 605, 903, 154, 293, 383, 422, 717, 719, 896, 448, 727, 772, 539};
	int arr[] = {712, 254, 869};
	vector<int> vec;
	for(int i=0;i<sizeof(arr)/sizeof(arr[0]);++i)
		vec.push_back(arr[i]);
	BoxesDiv2 bd;
	cout << bd.findSize(vec) << endl;
	return 0;
}
