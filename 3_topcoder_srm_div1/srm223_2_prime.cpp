/*

Problem Statement
    
You will be given a string of digits that supposedly come from three prime numbers. The digits will be given in a random order. Your task is to find the three prime numbers, if they exist. If there are three such primes, return them sorted least to greatest. If there is more than one possible set of three primes, return the set with the smallest product. If there is no such set, return { }.
For example, the five digits of the primes 5, 13, and 19 could be given to you as "39151". There are several other sets of prime numbers that could also be rearranged to give this input, for example { 5, 31, 19 } and { 3, 11, 59 }. The set with the smallest product is { 5, 13, 19 }, so those are the three primes your method should return.
Each digit of each prime will be present in the input. For example, if the input contains exactly two occurrences of the digit "1" (as in the example above), you must use the digit "1" exactly twice.
Any zeros in the input may not be used as leading zeros in any of the three primes.
Definition
    
Class:
PrimeAnagrams
Method:
primes
Parameters:
string
Returns:
vector <int>
Method signature:
vector <int> primes(string anagram)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Notes
-
If you find two sets of primes with the same product, you have made a startling discovery!
Constraints
-
anagram will contain between 3 and 8 characters, inclusive.
-
Each character of anagram will be a digit.
Examples
0)

    
"39151"
Returns: { 5,  13,  19 }
This is the example from the problem statement.
1)

    
"921179"
Returns: { 2,  17,  199 }

2)

    
"01123"
Returns: { 2,  3,  101 }
The input may have a leading zero, but the primes may not. {2, 3, 011} is not a valid answer.
3)

    
"0707070"
Returns: { }

4)

    
"222"
Returns: { 2,  2,  2 }

5)

    
"123"
Returns: { }
1 is not prime.
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class PrimeAnagrams{
public:
	vector <int> primes(string anagram){
		vector<int> res;
		int n = anagram.size();
		vector<int> elems(n,0);
		for(int i=0;i<n;++i)
			elems[i] = (int)(anagram[i]-'0');
		sort(elems.begin(),elems.end());
		int mini = INT_MAX;
		int v1,v2,v3;
		do{
			if(elems[0]==0) continue;
			for(int i=0;i<n/3;++i){
				if(elems[i+1]==0) continue;
				v1=0;
				for(int k=0;k<=i;++k)
					v1 = v1*10 + elems[k];
				if(!isP(v1)) continue;
				for(int j=max(i+i,i+1);j<=n*2/3;++j){
					if(elems[j+1]==0) continue;
					v2=0;
					for(int k=i+1;k<=j;++k)
						v2 = v2*10 + elems[k];
					if(!isP(v2)) continue;
					v3=0;
					for(int k=j+1;k<n;++k)
						v3 = v3*10 + elems[k];
					if(!isP(v3)||v1*v2*v3>=mini) continue;
					res.clear();
					res.push_back(v1); res.push_back(v2); res.push_back(v3);
					mini = v1*v2*v3;
				}//for(int j			
			}// for(int i
		}while(next_permutation(elems.begin(),elems.end()));
		sort(res.begin(),res.end());
		return res;
	}
	bool isP(int n){
		if(n<=1) return false;
		if(n==2) return true;
		if(n%2==0) return false;
		for(int i=3;i*i<=n;i+=2)
			if(n%i==0) return false;
		return true;
	}
};
