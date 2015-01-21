/*

Problem Statement
    
The King of Byteland likes integer factorization. Your task is to help him factor the number N. You will be given the long long N and you should return a vector<long long> containing all prime factors of N sorted in non-decreasing order. Note that some primes may occur multiple times in the prime factorization of N. For example, for N = 60 the only correct return value is {2, 2, 3, 5} because 2*2*3*5 = 60.

To make this task easier, the King has decided to give you a hint. He already knows the correct factorization and he will tell you every second number in the correct return value. More precisely, in addition to N you will be given a vector<long long> primes. The number of elements in primes will be (M+1)/2, rounded down, where M is the number of elements in the correct return value. For each valid i, primes[i] will be equal to the element 2i of the correct return value. (All indices are 0-based.)

Given N and primes, return the vector<long long> containing the factorization of N.
Definition
    
Class:
TheKingsFactorization
Method:
getVector
Parameters:
long long, vector<long long>
Returns:
vector<long long>
Method signature:
vector<long long> getVector(long long N, vector<long long> primes)
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
N will be between 2 and 1,000,000,000,000,000,000 (10^18), inclusive.
-
primes will contain the correct prime factors (as defined in the problem statement).
Examples
0)

    
12
{2, 3}
Returns: {2, 2, 3 }

1)

    
7
{7}
Returns: {7 }

2)

    
1764
{2, 3, 7}
Returns: {2, 2, 3, 3, 7, 7 }

3)

    
49
{7}
Returns: {7, 7 }

4)

    
210
{2, 5}
Returns: {2, 3, 5, 7 }

5)

    
100000
{2, 2, 2, 5, 5}
Returns: {2, 2, 2, 2, 2, 5, 5, 5, 5, 5 }

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
using namespace std;

class TheKingsFactorization{
public:
	vector<long long> getVector(long long N, vector<long long> primes){
		vector<long long> res;
		int n = primes.size();
		for(int i=0;i<n;++i)
			N /= primes[i];
		for(int i=0;i<n;++i){
			res.push_back(primes[i]);
			if(N==1) break;
			if(isP(N)) {res.push_back(N); N = 1; continue;}
			if(N%primes[i]==0){
				res.push_back(primes[i]);
				N /= primes[i];
			}else{
				if(i+1==n){ res.push_back(N); break;}
				for(long long k=primes[i]+1;k<=primes[i+1];++k)
					if(isP(k)&&N%k==0){
						res.push_back(k);
						N /= k;
						break;
					}
			}
		}
		//for(int i=0;i<res.size();++i)
		//	cout << res[i] << " ";
		//cout << endl;
		return res;
	}
	bool isP(int n){
		if(n<=1) return false;
		if(n==2) return true;
		if(n%2==0) return false;
		for(int i=3;i*i<=n;i+=2){
			if(n%i==0) return false;
		}
		return true;
	}
};
