/*

Problem Statement
    
You have been given a "word search" puzzle, which consists of a rectangular grid of letters, in which several words are hidden. Each word may begin anywhere in the puzzle, and may be oriented in any straight line horizontally, vertically, or diagonally. However, the words must all go down, right, or down-right. (see examples)
You are given a vector <string>, grid, indicating the letters in the grid to be searched. Character j of element i of grid is the letter at row i, column j. You are also given a vector <string>, wordList, indicating the words to be found in the grid. You are to return a vector <string> indicating the locations of each word within the grid.
The return value should have the same number of elements as wordList. Each element of wordList corresponds to the element of the return value with the same index.
Each element of the return value should be formatted as "row col" (quotes added for clarity), where row is the 0-based row in which the first letter of the word is found, and col is the 0-based column in which the first letter of the word is found. If the same word can be found more than once, the location in the lowest-indexed row should be returned. If there is still a tie, return the location with the lowest-indexed column. If a word cannot be found in the grid, return an empty string for that element.
Definition
    
Class:
WordFind
Method:
findWords
Parameters:
vector <string>, vector <string>
Returns:
vector <string>
Method signature:
vector <string> findWords(vector <string> grid, vector <string> wordList)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Constraints
-
grid will contain between 1 and 50 elements, inclusive.
-
Each element of grid will contain between 1 and 50 characters, inclusive.
-
Each element of grid will contain the same number of characters.
-
Each character of each element of grid will be 'A'-'Z'.
-
wordList will contain between 1 and 50 elements, inclusive.
-
Each element of wordList will contain between 1 and 50 characters, inclusive.
-
Each character of each element of wordList will be 'A'-'Z'.
Examples
0)

    
{"TEST",
 "GOAT",
 "BOAT"}
{"GOAT", "BOAT", "TEST"}
Returns: { "1 0",
  "2 0",
  "0 0" }
These words are pretty easy to find.
1)

    
{"SXXX",
 "XQXM",
 "XXLA",
 "XXXR"}
{"SQL", "RAM"}
Returns: { "0 0",
  "" }
While "RAM" may be found going up at "3 3", we are only allowing words that go down and right.
2)

    
{"EASYTOFINDEAGSRVHOTCJYG",
 "FLVENKDHCESOXXXXFAGJKEO",
 "YHEDYNAIRQGIZECGXQLKDBI",
 "DEIJFKABAQSIHSNDLOMYJIN",
 "CKXINIMMNGRNSNRGIWQLWOG",
 "VOFQDROQGCWDKOUYRAFUCDO",
 "PFLXWTYKOITSURQJGEGSPGG"}
{"EASYTOFIND", "DIAG", "GOING", "THISISTOOLONGTOFITINTHISPUZZLE"}
Returns: { "0 0",
  "1 6",
  "0 22",
  "" }

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
using namespace std;

class WordFind{
public:
	vector <string> findWords(vector <string> grid, 
			vector <string> wordList){
		vector<string> res;
		int m = grid.size();
		int n = grid[0].size();
		for(int i=0;i<wordList.size();++i){
			string cur = "";
			bool NF = true;
			int len = wordList[i].size();
			for(int r=0;NF&&r<m;++r)
			for(int c=0;NF&&c<n;++c){
				int k;
				//horizontal
				for(k=0;k<len&&r+k<m;++k)
					if(wordList[i][k]!=grid[r+k][c]) break;
				if(k==len){ cur = to_string(r)+" "+to_string(c); NF = false;}
				//vertical
				for(k=0;NF&&k<len&&c+k<n;++k)
					if(wordList[i][k]!=grid[r][c+k]) break;
				if(k==len){ cur = to_string(r)+" "+to_string(c); NF = false;}
				//diagnal
				for(k=0;NF&&k<len&&r+k<m&&c+k<n;++k)
					if(wordList[i][k]!=grid[r+k][c+k]) break;
				if(k==len){ cur = to_string(r)+" "+to_string(c); NF = false;}
			}
			//cout << "cur: " << cur << endl;
			res.push_back(cur);
		}
		return res;
	}
};
