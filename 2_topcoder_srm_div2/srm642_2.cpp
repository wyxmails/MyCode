/*
Problem Statement
    
Leo has N lights in a row. The lights are numbered 1 through N. Each light is either on or off.
Leo wants to turn all the lights off. He has N switches he may use. The switches are also numbered 1 through N. For each i, switch number i toggles the state of all lights whose numbers are multiples of i. (For example, switch 3 will toggle the state of light 3, light 6, light 9, and so on.)
You are given the current state of all lights as a string state with N characters. For each valid i, state[i] is either 'Y' (meaning that light i+1 is currently on) or 'N' (meaning that the light is off). Determine the smallest number of switches Leo needs to press in order to turn off all the lights. If there is no way to turn off all the lights, return -1 instead.
Definition
    
Class:
LightSwitchingPuzzle
Method:
minFlips
Parameters:
string
Returns:
int
Method signature:
int minFlips(string state)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Stack limit (MB):
256
Constraints
-
state will contain between 1 and 1000 characters, inclusive.
-
Each character of state will be either 'Y' or 'N'.
Examples
0)

    
"YYYYYY"
Returns: 1
We can turn off all the lights by pressing switch 1.
1)

    
"YNYNYNYNY"
Returns: 2
We cannot turn these lights off in a single step. It can be done in two steps. One possible solution looks as follows: First, press the second switch. This will toggle lights with numbers 2, 4, 6, and 8. The state of the lights after this change will be "YYYYYYYYY". Next, press the first switch to toggle all lightbulbs.
2)

    
"NNNNNNNNNN"
Returns: 0
All the lights are already off.
3)

    
"YYYNYYYNYYYNYYNYYYYN"
Returns: 4

4)

    
"NYNNYNNNYNNNNYNNNNNYNNNNNNYNNNNNNNY"
Returns: 12

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

class LightSwitchingPuzzle{
public:
	int minFlips(string state){
		int n=state.size();
		int res=0;
		for(int i=0;i<n;++i){
			if(state[i]=='Y'){
				res++;
				for(int j=i;j<n;j+=(i+1)){
					state[j] = state[j]=='Y'?'N':'Y';
				}
			}
		}
		return res;
	}
};
