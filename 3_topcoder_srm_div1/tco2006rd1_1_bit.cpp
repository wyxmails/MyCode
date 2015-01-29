/*

Problem Statement
    
You are analyzing a communications network with at most 18 nodes. Character j in element i (both 0-based) of mat denotes whether nodes i and j can communicate ('Y' for yes, 'N' for no). Assuming a node cannot communicate with two nodes at once, return the maximum number of nodes that can communicate simultaneously.
Definition
    
Class:
SeparateConnections
Method:
howMany
Parameters:
vector <string>
Returns:
int
Method signature:
int howMany(vector <string> mat)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Notes
-
If node S is communicating with node T then node T is communicating with node S.
Constraints
-
mat will contain between 1 and 18 elements inclusive.
-
Each element of mat will contain exactly N characters, where N is the number of elements in mat.
-
Each character in mat will be 'Y' or 'N'.
-
Character i of element i of mat will be 'N'.
-
Character i of element j will be the same as character j of element i.
Examples
0)

    
{
"NYYYY",
"YNNNN",
"YNNNN",
"YNNNN",
"YNNNN"
}
Returns: 2
All communications must occur with node 0. Since node 0 can only communicate with 1 node at a time, the returned value is 2.
1)

    
{
"NYYYY",
"YNNNN",
"YNNNY",
"YNNNY",
"YNYYN"
}
Returns: 4
In this setup, we can let node 0 communicate with node 1, and node 3 communicate with node 4.
2)

    
{
"NNYYYYYYYYYYYYYYYY",
"NNYYYYYYYYYYYYYYYY",
"YYNNNNNNNNNNNNNNNN",
"YYNNNNNNNNNNNNNNNN",
"YYNNNNNNNNNNNNNNNN",
"YYNNNNNNNNNNNNNNNN",
"YYNNNNNNNNNNNNNNNN",
"YYNNNNNNNNNNNNNNNN",
"YYNNNNNNNNNNNNNNNN",
"YYNNNNNNNNNNNNNNNN",
"YYNNNNNNNNNNNNNNNN",
"YYNNNNNNNNNNNNNNNN",
"YYNNNNNNNNNNNNNNNN",
"YYNNNNNNNNNNNNNNNN",
"YYNNNNNNNNNNNNNNNN",
"YYNNNNNNNNNNNNNNNN",
"YYNNNNNNNNNNNNNNNN",
"YYNNNNNNNNNNNNNNNN"
}
Returns: 4

3)

    
{
"NNNNNNNNNYNNNNNYN",
"NNNNNNNNNNNNNNNNN",
"NNNNNNNYNNNNNNNNN",
"NNNNNYNNNNNYNNYYY",
"NNNNNNNNNNNNNNNYN",
"NNNYNNNNNNNNNNYNN",
"NNNNNNNNNYNNNNNNN",
"NNYNNNNNNNNNNNNNN",
"NNNNNNNNNYNNNNNNN",
"YNNNNNYNYNNNNNNNY",
"NNNNNNNNNNNNNNNNN",
"NNNYNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNN",
"NNNYNYNNNNNNNNNNN",
"YNNYYNNNNNNNNNNNN",
"NNNYNNNNNYNNNNNNN"
}
Returns: 10

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
using namespace std;

static int dp[1<<18];

class SeparateConnections{
public:
	int howMany(vector <string> mat){
		int n = mat.size();
		int n2 = 1<<n;
		dp[0] = 0;
		for(int i=1;i<n2;++i){
			int bot = i&(~(i-1));
			int use = __builtin_ctz(bot);
			//cout << bot << " " << use << endl;
			dp[i] = dp[i^bot];
			for(int j=use+1;j<n;++j)
			if((i&(1<<j))&&mat[use][j]=='Y')
				dp[i] = max(dp[i],dp[i^bot^(1<<j)]+2);
		}
		return dp[n2-1];
	}
};
