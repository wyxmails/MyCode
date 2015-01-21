/*

Problem Statement
    
Grazyna works in a laboratory. Her team is about to perform an experiment with special bacteria.
There is a row of vessels. Each vessel contains a colony of bacteria. The colonies may currently have different sizes. Namely, for each valid i there are currently colonies[i] bacteria in the i-th vessel (0-based index).
Grazyna has a theory about how the colony sizes change. According to the theory, the colony sizes only change during nights and it only happens in two specific cases:
If during a day a colony finds itself immediately between two larger colonies, during the next night its size will increase by 1.
If during a day a colony finds itself immediately between two smaller colonies, during the next night its size will decrease by 1.
Note that the colonies in the first and last vessel never change their sizes as they are never between two colonies. Also note that multiple colonies can change their size each night.
The experiment will go on for as long as some colonies keep changing their sizes. You are given the vector <int> colonies. Compute the result of the experiment, assuming that the colony sizes change according to Grazyna's theory. Return a vector <int> with the same number of elements as colonies. For each valid i, element i of the return value should be the final size of the colony in the i-th vessel.
Definition
    
Class:
BacteriesColony
Method:
performTheExperiment
Parameters:
vector <int>
Returns:
vector <int>
Method signature:
vector <int> performTheExperiment(vector <int> colonies)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Stack limit (MB):
256
Notes
-
For each valid input the experiment will terminate after finitely many steps.
Constraints
-
colonies will have between 3 and 50 elements, inclusive.
-
Each element of colonies will be between 1 and 100, inclusive.
Examples
0)

    
{5, 3, 4, 6, 1 }
Returns: {5, 4, 4, 4, 1 }
The colony sizes during the first day are given as input: {5, 3, 4, 6, 1}.
During the first night colony 1 (0-based index) will grow and colony 3 will shrink.
During the second day the colony sizes will be {5, 4, 4, 5, 1}.
During the second night colony 3 will shrink again.
During the third day the colony sizes will be {5, 4, 4, 4, 1}.
There are no more changes during the third night, so that is the final state and the experiment ends.
1)

    
{1, 5, 4, 9 }
Returns: {1, 4, 5, 9 }
During the first night colony 1 will shrink from 5 to 4 and at the same time colony 2 will grow from 4 to 5. Afterwards there will be no more changes.
2)

    
{78, 34, 3, 54, 44, 99 }
Returns: {78, 34, 34, 49, 49, 99 }

3)

    
{32, 68, 50, 89, 34, 56, 47, 30, 82, 7, 21, 16, 82, 24, 91 }
Returns: {32, 59, 59, 59, 47, 47, 47, 47, 47, 18, 18, 19, 53, 53, 91 }

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/
#include <iostream>
#include <vector>
using namespace std;

class BacteriesColony{
public:
	vector <int> performTheExperiment(vector <int> colonies){
		vector<int> res = colonies;
		int n = colonies.size();
		bool changed = true;
		while(changed){
			changed = false;
			for(int i=1;i+1<n;++i){
				if(res[i]>res[i-1]&&res[i]>res[i+1]){changed = true; colonies[i]--;}
				if(res[i]<res[i-1]&&res[i]<res[i+1]){changed = true; colonies[i]++;}
			}
			res = colonies;
		}
		return res;
	}
};
