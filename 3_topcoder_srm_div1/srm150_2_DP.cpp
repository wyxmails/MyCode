/*

Problem Statement
    
Karel is a frustrated painter who works by day in an electrical repair shop. Inspired by the color-coded bands on resistors, he is painting a series of long, narrow canvases with bold colored stripes. However, Karel is lazy and wants to minimize the number of brush strokes it takes to paint each canvas.
Abbreviating each color to a single uppercase letter, Karel would write the stripe pattern red-green-blue-green-red as "RGBGR" (quotes added for clarity). It would take him three brush strokes to paint this pattern. The first stroke would cover the entire canvas in red (RRRRR). The second stroke would leave a band of red on either side and fill in the rest with green (RGGGR). The final brush stroke would fill in the blue stripe in the center (RGBGR).
Given a stripe pattern stripes as a string, calculate the minimum number of brush strokes required to paint that pattern.
Definition
    
Class:
StripePainter
Method:
minStrokes
Parameters:
string
Returns:
int
Method signature:
int minStrokes(string stripes)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Notes
-
The blank canvas is an ugly color and must not show through.
Constraints
-
stripes will contain only uppercase letters ('A'-'Z', inclusive).
-
stripes will contain between 1 and 50 characters, inclusive.
Examples
0)

    
"RGBGR"
Returns: 3
Example from introduction.
1)

    
"RGRG"
Returns: 3
This example cannot be done in two strokes, even though there are only two colors. Suppose you tried to paint both red stripes in one stroke, followed by both green stripes in one stroke. Then the green stroke would cover up the second red stripe. If you tried to paint both green stripes first, followed the red stripes, then the red stroke would cover up the first green stripe.
2)

    
"ABACADA"
Returns: 4
One long stroke in color 'A', followed by one stroke each in colors 'B', 'C', and 'D'.
3)

    
"AABBCCDDCCBBAABBCCDD"
Returns: 7

4)

    
"BECBBDDEEBABDCADEAAEABCACBDBEECDEDEACACCBEDABEDADD"
Returns: 26

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class StripePainter{
public:
	int minStrokes(string stripes){
		int n = stripes.size();
		if(n<=1) return n;
		string tmp = stripes.substr(0,1);
		for(int i=1;i<n;++i){
			if(stripes[i]==stripes[i-1]) continue;
			tmp += stripes[i];
		}
		n = tmp.size();
		vector<vector<int> > mark(n+1,vector<int>(n+1,0));
		for(int i=0;i<=n;++i) mark[i][i] = 1;
		for(int step=2;step<=n;++step){
			for(int j=0;j+step-1<n;++j){
				int s = j;
				int e = s+step-1;
				vector<int> same;
				for(int k=s;k<=e;++k)
					if(tmp[k]==tmp[s]) same.push_back(k);
				same.push_back(e+1);
				int m = same.size();
				vector<int> level(m,INT_MAX);
				level[0] = 0;
				for(int k=1;k<level.size();++k){
					for(int q=0;q<k;++q){
						level[k] = min(level[k],level[q]+mark[same[q]+1][same[k]-1]);
					}
				}
				mark[s][e] = level[m-1]+1;
			}
		}
		return mark[0][n-1];
	}
};
