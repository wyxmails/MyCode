/*
 Problem Statement

 Frog Suwako lives on a two-dimensional plane. She likes to jump. Currently, she is located in the point (0, 0). She would like to reach the point (x, y). You are given the ints x and y.   Suwako wants to reach the desired destination in a specific way: using a series of jumps with pre-determined lengths. You are given these lengths in a vector <int> jumpLenghts. For example, if jumpLengths = { 2, 5 }, Suwako must make a jump of length exactly 2, followed by a jump of length exactly 5.   Note that Suwako can jump onto arbitrary points in the plane, they are not required to have integer coordinates. Return "Able" (quotes for clarity) if Suwako is able to reach her desired destination from (0, 0) using the desired sequence of jump lengths. Otherwise, return "Not able".
 Definition

Class:
 Jumping
Method:
 ableToGet
Parameters:
 int, int, vector <int>
Returns:
 string
 Method signature:
 string ableToGet(int x, int y, vector <int> jumpLengths)
 (be sure your method is public)
 Limits
 
 Time limit (s):
 2.000
 Memory limit (MB):
 256
 Constraints
 -
 x will be between -1,000 and 1,000, inclusive.
 -
 y will be between -1,000 and 1,000, inclusive.
 -
 len will contain between 1 and 50 elements, inclusive.
 -
 Each element in len will be between 1 and 1,000, inclusive.
 Examples
 test 0)
 5 4
 {2, 5}
Returns: "Able"
 One possibility is to jump from (0, 0) to (2, 0), and then from (2, 0) to (5, 4).
 test 1)
 3 4
 {4}
Returns: "Not able"
 The distance from (0, 0) to (3, 4) is 5. You cannot get there using a single jump of length 4 - it is too short.
 test 2)
 3 4
 {6}
Returns: "Not able"
 The distance from (0, 0) to (3, 4) is 5. You cannot get there using a single jump of length 6 - it is too long.
 test 3)
 0 1
 {100, 100}
Returns: "Able"
 Here, one possible solution looks as follows: Let t = sqrt(100*100 - 0.5*0.5). Suwoko will make her first jump from (0, 0) to (t, 0.5), and her second jump from (t, 0.5) to (0, 1).
 test 4)
 300 400
 {500}
Returns: "Able"
 test 5)
 11 12
 {1,2,3,4,5,6,7,8,9,10}
Returns: "Able"
 test 6)
 11 12
 {1,2,3,4,5,6,7,8,9,100}
Returns: "Not able"
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <map>
using namespace std;

class Jumping{
public:
	string ableToGet(int x,int y,vector<int>jumpLengths);
};

string Jumping::ableToGet(int x,int y,vector<int> jumpLengths){
	double len = sqrt(x*x+y*y);
	double sum = len;
	for(int i=0;i<jumpLengths.size();++i){
		sum += jumpLengths[i];
	}   
	if(len>sum-len) return "Not able";
	for(int i=0;i<jumpLengths.size();++i){
		if(jumpLengths[i]>sum-jumpLengths[i])
			return "Not able";
	}
	return "Able";
}

int main(){
	//int arr[] = {530, 701, 509, 753, 257, 257, 120, 712, 352, 844, 706, 109, 394};
	int arr[] = {711, 237};
	vector<int> J;//(50,1000);
	int n = sizeof(arr)/sizeof(arr[0]);
	for(int i=0;i<n;++i)
		J.push_back(arr[i]);
	srand(time(NULL));
	int x = -350;//421;//rand()%1000;
	int y = 215;//326;//rand()%1000;
	Jumping obj;
	string res = obj.ableToGet(x,y,J);
	cout << res << endl;
	return 0;
}
