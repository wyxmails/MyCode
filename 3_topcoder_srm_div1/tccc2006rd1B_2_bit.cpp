/*

Problem Statement
    
The ACME company is building a factory complex in your county which has k cities. The factory complex is split into n part-building factories and m part-assembling factories. Each factory must be built in a different city of your county because of polution regulations, and there must be a direct road between each building factory and each assembling factory.  You will be given a vector <string> county. Character j of element i of county will be 'Y' if there is a direct road between city i and city j, and 'N' if there isn't. All roads are bidirectional. Return the number of ways the factory complex can be built in this county. Two factory complexes are different if the set of cities containing part-building factories is different in one than the other, or the set of cities containing part-assembling factories is different in one than the other
Definition
    
Class:
FactoryCounting
Method:
count
Parameters:
int, int, vector <string>
Returns:
long long
Method signature:
long long count(int n, int m, vector <string> county)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Constraints
-
n and m will each be between 1 and 8, inclusive.
-
county will have between 1 and 30 elements, inclusive.
-
Each element of county will have exactly k characters, where k is the number of elements in county.
-
Each character in each element of county will be either 'Y' or 'N'.
-
Character i of element i will always be 'N'.
-
For all i and j, where i != j, character i of element j of county will be equal to character j of element i.
Examples
0)

    
2
1
{
 "NYY",
 "YNY",
 "YYN"}
Returns: 3
Here we have the following possibilities:
part-building factories: {1, 2} part-assembling factories: {3}
part-building factories: {1, 3} part-assembling factories: {2}
part-building factories: {2, 3} part-assembling factories: {1}
1)

    
2
2
{
 "NYYYYN",
 "YNYYNY",
 "YYNYYY",
 "YYYNYN",
 "YNYYNY",
 "NYYNYN"}
Returns: 32

2)

    
1
1
{
 "NNNNYN",
 "NNNYNN",
 "NNNNYN",
 "NYNNYN",
 "YNYYNN",
 "NNNNNN"}
Returns: 8
There are a total of 4 direct roads. For each direct road connecting cities a and b, we have two options: we can either put a part-building factory in city a and a part-assembling factory in city b, or vice versa. Therefore, we have a total 8 possible factory complexes.
3)

    
3
3
{
 "NYYYNYYNYY",
 "YNYYYYYYYN",
 "YYNYYYNYYN",
 "YYYNYYNYNY",
 "NYYYNYYYYY",
 "YYYYYNYYNY",
 "YYNNYYNYYN",
 "NYYYYYYNNY",
 "YYYNYNYNNY",
 "YNNYYYNYYN"}
Returns: 308

4)

    
7
8
{
 "NYYYYYNYYYYYNYYYYYYYYYYNYYYYYY",
 "YNYYYYYYYYYYYYYYYNYYYYYYYYYYYY",
 "YYNYYYYYYYYYYYYNYNYYYNNYYYNYYY",
 "YYYNYYYYYYYYNYYYYYNYYYYYYNYYYY",
 "YYYYNYYYYYYYYYNYYYYYYYYYYYNYYY",
 "YYYYYNYYNYYYYNYYYYYNYYYYYYYNNY",
 "NYYYYYNYYYYYYYYYNYYYYNYYYYYYYY",
 "YYYYYYYNYYYYYYYYYYYYYYYYYYYYYY",
 "YYYYYNYYNYYYYNNYYYYYYYYNYYNNYY",
 "YYYYYYYYYNYYNYYNYNYYNYYYYYYYYY",
 "YYYYYYYYYYNYYNYYYYYYYNYYYYYYYY",
 "YYYYYYYYYYYNYYYYNYYYYYYYYYYYYY",
 "NYYNYYYYYNYYNYYYNYNYYYYYNYYYYY",
 "YYYYYNYYNYNYYNYYYYYYYYYYYNYYNY",
 "YYYYNYYYNYYYYYNNNYYYYYYYYYYYYY",
 "YYNYYYYYYNYYYYNNYNYYYYYNNYYYNY",
 "YYYYYYNYYYYNNYNYNNYYNYYYYYNYNY",
 "YNNYYYYYYNYYYYYNNNYYNYYYYYYYYY",
 "YYYNYYYYYYYYNYYYYYNNYYNYYYYYYY",
 "YYYYYNYYYYYYYYYYYYNNYYYYYYYYYY",
 "YYYYYYYYYNYYYYYYNNYYNYYYYYNYYY",
 "YYNYYYNYYYNYYYYYYYYYYNYYYYYYYY",
 "YYNYYYYYYYYYYYYYYYNYYYNYYYYYYY",
 "NYYYYYYYNYYYYYYNYYYYYYYNYYYYYY",
 "YYYYYYYYYYYYNYYNYYYYYYYYNYYYYY",
 "YYYNYYYYYYYYYNYYYYYYYYYYYNYYYY",
 "YYNYNYYYNYYYYYYYNYYYNYYYYYNYYY",
 "YYYYYNYYNYYYYYYYYYYYYYYYYYYNYY",
 "YYYYYNYYYYYYYNYNNYYYYYYYYYYYNN",
 "YYYYYYYYYYYYYYYYYYYYYYYYYYYYNN"}
Returns: 522891760

5)

    
8
8
{
 "NYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
 "YNYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
 "YYNYYYYYYYYYYYYYYYYYYYYYYYYYYY",
 "YYYNYYYYYYYYYYYYYYYYYYYYYYYYYY",
 "YYYYNYYYYYYYYYYYYYYYYYYYYYYYYY",
 "YYYYYNYYYYYYYYYYYYYYYYYYYYYYYY",
 "YYYYYYNYYYYYYYYYYYYYYYYYYYYYYY",
 "YYYYYYYNYYYYYYYYYYYYYYYYYYYYYY",
 "YYYYYYYYNYYYYYYYYYYYYYYYYYYYYY",
 "YYYYYYYYYNYYYYYYYYYYYYYYYYYYYY",
 "YYYYYYYYYYNYYYYYYYYYYYYYYYYYYY",
 "YYYYYYYYYYYNYYYYYYYYYYYYYYYYYY",
 "YYYYYYYYYYYYNYYYYYYYYYYYYYYYYY",
 "YYYYYYYYYYYYYNYYYYYYYYYYYYYYYY",
 "YYYYYYYYYYYYYYNYYYYYYYYYYYYYYY",
 "YYYYYYYYYYYYYYYNYYYYYYYYYYYYYY",
 "YYYYYYYYYYYYYYYYNYYYYYYYYYYYYY",
 "YYYYYYYYYYYYYYYYYNYYYYYYYYYYYY",
 "YYYYYYYYYYYYYYYYYYNYYYYYYYYYYY",
 "YYYYYYYYYYYYYYYYYYYNYYYYYYYYYY",
 "YYYYYYYYYYYYYYYYYYYYNYYYYYYYYY",
 "YYYYYYYYYYYYYYYYYYYYYNYYYYYYYY",
 "YYYYYYYYYYYYYYYYYYYYYYNYYYYYYY",
 "YYYYYYYYYYYYYYYYYYYYYYYNYYYYYY",
 "YYYYYYYYYYYYYYYYYYYYYYYYNYYYYY",
 "YYYYYYYYYYYYYYYYYYYYYYYYYNYYYY",
 "YYYYYYYYYYYYYYYYYYYYYYYYYYNYYY",
 "YYYYYYYYYYYYYYYYYYYYYYYYYYYNYY",
 "YYYYYYYYYYYYYYYYYYYYYYYYYYYYNY",
 "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYN"}
Returns: 1871589827250

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
using namespace std;

class FactoryCounting{
public:
	long long count(int n, int m, vector <string> county){
		int len = county.size();
		vector<int> bitset(len,0);
		for(int i=0;i<len;++i){
			for(int j=0;j<len;++j)
				if(county[i][j]=='Y') bitset[i] |= (1<<j);
		}
		int bit = (1<<len)-1;
		return myC(n,m,bitset,0,bit);
	}
	long long myC(int n,int m,const vector<int> county,int cur,int bit){
		long long res = 0;
		if(n==0){
			int k = countB(bit);
			return combi(k,m);
		}
		if(cur+n>county.size()) return 0;
		int pb = bit;
		bit &= county[cur];
		res += myC(n-1,m,county,cur+1,bit);
		if(cur+1+n<=county.size()) res += myC(n,m,county,cur+1,pb);
		return res;
	}
	int countB(int bit){
		int res = 0;
		while(bit>0){
			bit &= (bit-1);
			res++;
		}
		return res;
	}
	long long combi(int k,int m){
		if(k<m) return 0;
		if(k==m) return 1;
		long long kk = k,mm=m;
		long long res = 1;
		long long start = max(mm+1,kk-mm+1);
		long long end = min(mm,kk-mm);
		for(long long i=start;i<=kk;++i)
			res *= i;
		for(long long i=2;i<=end;++i)
			res /= i;
		return res;
	}
};
