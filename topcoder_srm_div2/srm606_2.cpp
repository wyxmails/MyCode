/*
Problem Statement
    
Elly and Kris play the following game. In the beginning Kristina thinks of a number between 1 and 1,000,000,000, inclusive. After that Elly starts trying to guess it. In each round she says a number and Kristina says what is the absolute difference between the number she has thought of, and the number Elly guessed. Now Elly wonders if the guesses she has already made are sufficient to uniquely determine Kristina's number.  You are given a vector <int> guesses and a vector <int> answers of the same length. For each valid i, in round i of the game (0-based index) Elly guessed the number guesses[i] and Kristina answered answers[i]. If Kristina's number can be uniquely determined, return that number. If there are multiple possibilities that are consistent with the current set of guesses and answers, return -1. If it can be shown that at some point Kristina has lied (some of her answers were inconsistent), return -2.
Definition
    
Class:
EllysNumberGuessing
Method:
getNumber
Parameters:
vector <int>, vector <int>
Returns:
int
Method signature:
int getNumber(vector <int> guesses, vector <int> answers)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
guesses and answers will each contain between 1 and 50 elements, inclusive.
-
guesses and answers will contain the same number of elements.
-
Each element of guesses will be between 1 and 1,000,000,000, inclusive.
-
Each element of answers will be between 1 and 999,999,999, inclusive.
Examples
0)

    
{600, 594}
{6, 12}
Returns: 606
Apparently Kristina has thought of the number of this SRM.
1)

    
{100, 50, 34, 40}
{58, 8, 8, 2}
Returns: 42
It is not guaranteed that Elly has used a perfect strategy so far.
2)

    
{500000, 600000, 700000}
{120013, 220013, 79987}
Returns: -2
The answers here are inconsistent. After the second guess we can conclude that the answer is below 500000. But the third one indicates that it is above 500000. Thus, Kristina is a liar and you should return -2.
3)

    
{500000000}
{133742666}
Returns: -1
There are multiple possibilities here, thus you should return -1.
4)

    
{76938260, 523164588, 14196746, 296286419, 535893832,
 41243148, 364561227, 270003278, 472017422, 367932361,
 395758413, 301278456, 186276934, 316343129, 336557549,
 52536121, 98343562, 356769915, 89249181, 335191879}
{466274085, 20047757, 529015599, 246925926, 7318513,
 501969197, 178651118, 273209067, 71194923, 175279984,
 147453932, 241933889, 356935411, 226869216, 206654796,
 490676224, 444868783, 186442430, 453963164, 208020466}
Returns: 543212345

5)

    
{42}
{42}
Returns: 84
Don't forget that the number Kris has thought of must be between 1 and 1,000,000,000.
6)

    
{999900000}
{100001}
Returns: 999799999
Don't forget that the number Kris has thought of must be between 1 and 1,000,000,000.
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class EllysNumberGuessing{
public:
	int getNumber(vector <int> guesses, vector <int> answers){
		int Max = 1000000000,Min=1;
		int l=-1,r=-1;
		int n = guesses.size();
		for(int i=0;i<n;++i){
			int v1 = guesses[i]-answers[i];
			int v2 = guesses[i]+answers[i];
			if(v1<Min||v1>Max) v1 = -1;
			if(v2<Min||v2>Max) v2 = -1;
			if(l==-1&&r==-1){
				l = v1; r = v2;
			}else{
				if(v1!=l&&v1!=r) v1 = -1;
				if(v2!=l&&v2!=r) v2 = -1;
				l = v1; r = v2;
			}
			if(l==-1&&r==-1) return -2;
		}
		if(l==-1&&r==-1) return -2;
		if(l==-1||r==-1) return l==-1?r:l;
		return -1;
	}
};
