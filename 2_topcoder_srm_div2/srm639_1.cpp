/*

Problem Statement
    
Kirino has found a game in which she has to feed electronic pets. There are two pets in the game. You are given six ints st1,p1,t1,st2,p2,t2. To win the game, Kirino must satisfy the following rules:
She must feed her first pet for the first time precisely at the time st1.
There must be exactly p1 seconds between any two consecutive feedings of the first pet.
She must feed the first pet exactly t1 times.
She must feed her second pet for the first time precisely at the time st2.
There must be exactly p2 seconds between any two consecutive feedings of the second pet.
She must feed the second pet exactly t2 times.
Feeding the pets is easy if Kirino never needs to feed both pets at the same time. Return "Easy" (quotes for clarity) if feeding the pets is easy for the given inputs. Otherwise, return "Difficult". Note that the return value is case-sensitive.
Definition
    
Class:
ElectronicPetEasy
Method:
isDifficult
Parameters:
int, int, int, int, int, int
Returns:
string
Method signature:
string isDifficult(int st1, int p1, int t1, int st2, int p2, int t2)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
st1, p1, t1, st2, p2, and t2 will be between 1 and 1,000, inclusive.
Examples
0)

    
3
3
3
5
2
3
Returns: "Difficult"
Kirino must feed her first pet at the times 3, 6, and 9. She must feed her second pet at the times 5, 7, and 9. Feeding these two pets is difficult because she needs to feed both of them at the same time (at time 9).
1)

    
3
3
3
5
2
2
Returns: "Easy"
Kirino must feed her first pet at 3, 6, and 9, and her second pet at 5 and 7. As all of these times are distinct, feeding these two pets is easy.
2)

    
1
4
7
1
4
7
Returns: "Difficult"

3)

    
1
1000
1000
2
1000
1000
Returns: "Easy"

4)

    
1
1
1
2
2
2
Returns: "Easy"

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

class ElectronicPetEasy{
public:
	string isDifficult(int st1, int p1, int t1, int st2, int p2, int t2){
		while(t1>0&&t2>0){
			if(st1==st2) return "Difficult";
			if(st1>st2){
				st2 += p2;
				t2--;
			}else{
				st1 += p1;
				t1--;
			}
		}
		return "Easy";
	}
};
