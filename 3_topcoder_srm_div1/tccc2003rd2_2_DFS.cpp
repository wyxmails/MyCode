/*

Problem Statement
    
You work for a very large company that markets many different products. In some cases, one product you market competes with another. To help deal with this situation you have split the intended consumers into two groups, namely Adults and Teenagers. If your company markets 2 products that compete with each other, selling one to Adults and the other to Teenagers will help maximize profits. Given a list of the products that compete with each other, you are going to determine whether all can be marketed such that no pair of competing products are both sold to Teenagers or both sold to Adults. If such an arrangement is not feasible your method will return -1. Otherwise, it should return the number of possible ways of marketing all of the products.  The products will be given in a vector <string> compete whose kth element describes product k. The kth element will be a single-space delimited list of integers. These integers will refer to the products that the kth product competes with. For example:
compete = {"1 4",
            "2",
            "3",
            "0",
	    ""}
The example above shows product 0 competes with 1 and 4, product 1 competes with 2, product 2 competes with 3, and product 3 competes with 0. Note, competition is symmetric so product 1 competing with product 2 means product 2 competes with product 1 as well. Ways to market: 1) 0 to Teenagers, 1 to Adults, 2 to Teenagers, 3 to Adults, and 4 to Adults 2) 0 to Adults, 1 to Teenagers, 2 to Adults, 3 to Teenagers, and 4 to Teenagers Your method would return 2.
Definition
    
Class:
Marketing
Method:
howMany
Parameters:
vector <string>
Returns:
long long
Method signature:
long long howMany(vector <string> compete)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Constraints
-
compete will contain between 1 and 30 elements, inclusive.
-
Each element of compete will have between 0 and 50 characters, inclusive.
-
Each element of compete will be a single space delimited sequence of integers such that:
All of the integers are unique.
Each integer contains no extra leading zeros.
Each integer is between 0 and k-1 inclusive where k is the number of elements in compete.
-
No element of compete contains leading or trailing whitespace.
-
Element i of compete will not contain the value i.
-
If i occurs in the jth element of compete, j will not occur in the ith element of compete.
Examples
0)

    
{"1 4","2","3","0",""}
Returns: 2
The example from above.
1)

    
{"1","2","0"}
Returns: -1
Product 0 cannot be marketed with product 1 or 2. Product 1 cannot be marketed with product 2. There is no way to achieve a viable marketing scheme.
2)

    
{"1","2","3","0","0 5","1"}
Returns: 2

3)

    
{"","","","","","","","","","",
 "","","","","","","","","","",
 "","","","","","","","","",""}
Returns: 1073741824

4)

    
{"1","2","3","0","5","6","4"}
Returns: -1

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

class Marketing{
public:
	long long howMany(vector <string> compete){
		int n = compete.size();
		vector<vector<bool> > mark(n,vector<bool>(n,false));
		for(int i=0;i<n;++i){
			stringstream ss(compete[i]);
			int j;
			while(ss>>j){
				mark[i][j] = true;
				mark[j][i] = true;
			}
		}
		vector<int> used(n,0);
		int cnt=0;
		for(int i=0;i<n;++i){
			if(used[i]==0){
				cnt++;
				stack<int> ms;
				ms.push(i);
				used[i] = 1;
				while(!ms.empty()){
					int cur = ms.top();
					ms.pop();
					for(int j=0;j<n;++j){
						if(mark[cur][j]){
							if(used[cur]==used[j]) return -1;
							if(used[j]==0){
								used[j] = -used[cur];
								ms.push(j);
							}
						}
					}
				}
			}
		}
		long long res = pow(2,cnt);
		return res;
	}
};
