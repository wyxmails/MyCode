/*
 Problem Statement
     
 "Němec's quadratic law: how many minutes the teacher was late to the lesson, that many minutes squared he'll end the lesson earlier." 
  
 In other words, if the teacher is t minutes late (for some non-negative integer t), he should end the lesson t2 minutes early. Of course, this means the teacher can't be too late, because a lesson can't end before even starting. It is, however, possible for the teacher to arrive and end the lesson immediately (in fact, he then only arrives to tell the students that the lesson's cancelled).
  
 You're given a long long d. The lesson was supposed to take d minutes. Compute and return the largest non-negative integer t such that the teacher can be t minutes late.
 Definition
     
Class:
QuadraticLaw
Method:
getTime
Parameters:
long long
Returns:
long long
Method signature:
long long getTime(long long d)
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
d will be between 1 and 1,000,000,000,000,000,000, inclusive.
Examples
0)

    
1
Returns: 0
The lesson was supposed to take 1 minute. The teacher can only be 0 minutes late, in which case he ends the lesson 0 minutes early (i.e. he arrives and ends the lecture on time).
1)

    
2
Returns: 1
It's possible for the teacher to be 1 minute late and end the lecture 1 minute early (so there's no lecture at all).
2)

    
5
Returns: 1

3)

    
6
Returns: 2

4)

    
7
Returns: 2

5)

    
1482
Returns: 38

6)

    
1000000000000000000
Returns: 999999999

7)

    
31958809614643170
Returns: 178770270

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 */
#include <iostream>
#include <cmath>
using namespace std;

class QuadraticLaw{
	public:
		long getTime(long d);
};

long QuadraticLaw::getTime(long d){
	if(d<=2) return d-1;
	long res = sqrt(d);
	res--;
	while(res*(res+1)<d){
		res++;
	}
	if(res*(res+1)==d) return res;
	res--;
	return res;
}

int main(){
	QuadraticLaw ql;
	long d = 1;
	cout << "0: " << ql.getTime(d) << endl;
	d = 2;
	cout << "1: " << ql.getTime(d) << endl;
	d = 5;
	cout << "2: " << ql.getTime(d) << endl;
	d = 6;
	cout << "3: " << ql.getTime(d) << endl;
	d = 7;
	cout << "4: " << ql.getTime(d) << endl;
	d = 1482;
	cout << "5: " << ql.getTime(d) << endl;
	d = 1000000000000000000;
	cout << "6: " << ql.getTime(d) << endl;
	d = 31958809614643170;
	cout << "7: " << ql.getTime(d) << endl;
	return 0;
}
