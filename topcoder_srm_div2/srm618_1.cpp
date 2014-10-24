/*
 Problem Statement
     
 Fox Ciel wants to type a word on her old cell phone. The cell phone has only one button. The letter A is typed by tapping the button once, B by tapping it twice in a row, and so on, in alphabetical order. Thus, the last letter Z is typed by tapping the button 26 times without a pause.  You are given a string word. Compute and return the answer to the following question: How many times will Ciel tap the button while typing this word?
 Definition
     
Class:
WritingWords
Method:
write
Parameters:
string
Returns:
int
Method signature:
int write(string word)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Notes
-
While typing a word, Ciel has to make a short pause after typing each letter, so that the phone can tell when one letter ends and another letter begins. These pauses do not matter in this problem.
Constraints
-
word will contain between 1 and 50 characters, inclusive.
-
Each character in word will be an uppercase English letter ('A'-'Z').
Examples
0)

    
"A"
Returns: 1
One tap types the letter A.
1)

    
"ABC"
Returns: 6
To type ABC, Ciel will do the following:
Tap the button once to type A.
Tap the button twice to type B.
Tap the button three times to type C.
The total number of taps is 1+2+3 = 6.
2)

    
"VAMOSGIMNASIA"
Returns: 143

3)

    
"TOPCODER"
Returns: 96

4)

    
"SINGLEROUNDMATCH"
Returns: 183

5)

    
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ"
Returns: 1300

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
using namespace std;

class WritingWords{
public:
	int write(string word);
};

int WritingWords::write(string word){
	int res = 0;
	int n = word.size();
	for(int i=0;i<n;++i)
		res += int(word[i]-'A'+1);
	return res;
}
