/*

Problem Statement
    
Mirosz adores sweets. He has just bought a rectangular bar of chocolate. The bar is divided into a grid of square cells. Different cells may have a different quality. You are given the description of the bar in a vector <string> chocolate. Each character in chocolate is a digit between '0' and '9', inclusive: the quality of one of the cells.
 
Mirosz is now going to divide the chocolate into 9 parts: one for him and one for each of his 8 friends. He will do the division by making four cuts: two horizontal and two vertical ones. Each cut must go between two rows or columns of cells. Each of the 9 parts must be non-empty. The quality of a part is the sum of the qualities of all cells it contains.
 
Mirosz is well-mannered and he will let his friends choose their pieces first. His friends are even more addicted to chocolate than he is. Therefore, they will certainly choose the pieces with higher quality first, and Mirosz will be left with the worst of the nine pieces.
 
You are given the vector <string> chocolate. Find the optimal places for the four cuts. More precisely, compute and return the largest possible quality of Mirosz's part of the chocolate bar.
Definition
    
Class:
ChocolateDividingEasy
Method:
findBest
Parameters:
vector <string>
Returns:
int
Method signature:
int findBest(vector <string> chocolate)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
chocolate will contain between 3 and 50 elements, inclusive. 
-
All elements in chocolate will contain between 3 and 50 characters, inclusive. 
-
All elements in chocolate will contain the same number of characters. 
-
All elements in chocolate will contain only digits ('0'-'9').
Examples
0)

    
{
"9768",
"6767",
"5313"
}
Returns: 3
There are three valid ways to cut this chocolate. One of the optimal ones is shown below.  9 | 7 | 6 8 --|---|----- 6 | 7 | 6 7 --|---|----- 5 | 3 | 1 3   This way of cutting produces parts with the following qualities: 9, 7, 14, 6, 7, 13, 5, 3, and 4. The quality of the worst part (the one that Mirosz will get) is 3.  Here is another way of cutting the same chocolate:  9 7 | 6 | 8 ----|---|--- 6 7 | 6 | 7 ----|---|--- 5 3 | 1 | 3  If Mirosz cuts the chocolate in this way, the quality of his part will be 1, which is worse than 3.
1)

    
{
"36753562",
"91270936",
"06261879",
"20237592",
"28973612",
"93194784"
}
Returns: 15
There is only one optimal way to divide the chocolate:  3 6 7 5 | 3 5 | 6 2 9 1 2 7 | 0 9 | 3 6 --------|-----|----- 0 6 2 6 | 1 8 | 7 9 2 0 2 3 | 7 5 | 9 2 --------|-----|----- 2 8 9 7 | 3 6 | 1 2 9 3 1 9 | 4 7 | 8 4   The three parts on the top have qualities 3+6+7+5+9+1+2+7 = 40, 3+5+0+9 = 17 and 6+2+3+6 = 17 The worst part is the one in the bottom right corner. Its quality is only 1+2+4+8 = 15.
2)

    
{
"012",
"345",
"678"
}
Returns: 0

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
using namespace std;

class ChocolateDividingEasy{
public:
	int findBest(vector <string> choc){
		int m = choc.size();
		int n = choc[0].size();
		int sum=0;
		for(int i=0;i<m;++i)
		for(int j=0;j<n;++j)
			sum += (int)(choc[i][j]-'0');
		sum = sum/9;
		int res = 0;
		for(int x1=0;x1+2<m;++x1)
		for(int y1=0;y1+2<n;++y1)
		for(int x2=x1+1;x2+1<m;++x2)
			for(int y2=y1+1;y2+1<n;++y2){
				int cnt = count(choc,0,0,x1,y1);
				if(cnt<=res) continue;
				cnt = min(cnt,count(choc,0,y1+1,x1,y2));
				if(cnt<=res) continue;
				cnt = min(cnt,count(choc,0,y2+1,x1,n-1));
				if(cnt<=res) continue;
				cnt = min(cnt,count(choc,x1+1,0,x2,y1));
				if(cnt<=res) continue;
				cnt = min(cnt,count(choc,x1+1,y1+1,x2,y2));
				if(cnt<=res) continue;
				cnt = min(cnt,count(choc,x1+1,y2+1,x2,n-1));
				if(cnt<=res) continue;
				cnt = min(cnt,count(choc,x2+1,0,m-1,y1));
				if(cnt<=res) continue;
				cnt = min(cnt,count(choc,x2+1,y1+1,m-1,y2));
				if(cnt<=res) continue;
				cnt = min(cnt,count(choc,x2+1,y2+1,m-1,n-1));
				res = max(res,cnt);
				if(res == sum) return res;
			}
		return res;
	}
	int count(vector<string>&choc,int x1,int y1,int x2,int y2){
		int res = 0;
		for(int i=x1;i<=x2;++i)
		for(int j=y1;j<=y2;++j){
			res += (int)(choc[i][j]-'0');
		}
		return res;
	}
};
