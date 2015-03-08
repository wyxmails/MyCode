/*

Problem Statement
    
Little Elephant from the Zoo of Lviv has a bunch of books. You are given a vector <int> pages. Each element of pages is the number of pages in one of those books. There are no two books with the same number of pages.

You are also given a int number. As a homework from the teacher, Little Elephant must read exactly number of his books during the summer. (Little Elephant has strictly more than number books.)

All other elephants in the school also got the exact same homework. Little Elephant knows that the other elephants are lazy: they will simply pick the shortest number books, so that they have to read the smallest possible total number of pages. Little Elephant wants to be a good student and read a bit more than the other elephants. He wants to pick the subset of books with the second smallest number of pages. In other words, he wants to pick a subset of books with the following properties:
There are exactly number books in the chosen subset.
The total number of pages of those books is greater than the smallest possible total number of pages.
The total number of pages of those books is as small as possible (given the above conditions).

Return the total number of pages Little Elephant will have to read.
Definition
    
Class:
LittleElephantAndBooks
Method:
getNumber
Parameters:
vector <int>, int
Returns:
int
Method signature:
int getNumber(vector <int> pages, int number)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Constraints
-
pages will contain between 2 and 50 elements, inclusive.
-
Each element of pages will be between 1 and 100, inclusive.
-
There will be no two equal elements in pages.
-
number will be between 1 and N-1, inclusive, where N is the number of elements in pages.
Examples
0)

    
{1, 2}
1
Returns: 2
There are two books: one with 1 page, the other with 2 pages. As number=1, each of the elephants has to read one book. The lazy elephants will read the 1-page book, so our Little Elephant should read the 2-page one. Thus, the number of pages read by Little Elephant is 2.
1)

    
{74, 7, 4, 47, 44}
3
Returns: 58
The lazy elephants will read books 1, 2, and 4 (0-based indices). Their total number of pages is 7+4+44 = 55. Little Elephant should pick books 1, 2, and 3, for a total of 7+4+47 = 58 pages. (Note that Little Elephant is allowed to pick any subset, except for the minimal one. In particular, he may read some of the books read by the other elephants.)
2)

    
{3, 1, 9, 7, 2, 8, 6, 4, 5}
7
Returns: 29

3)

    
{74, 86, 32, 13, 100, 67, 77}
2
Returns: 80

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class LittleElephantAndBooks{
public:
	int getNumber(vector <int> pages, int number){
		sort(pages.begin(),pages.end());
		int total=0;
		for(int i=0;i<=number;++i){
			if(i+1==number) continue;
			total += pages[i];
		}
		return total;
	}
};
