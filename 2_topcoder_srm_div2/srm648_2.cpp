/*

Problem Statement
    
Lun the dog has found an undirected graph in Shuseki Forest. The graph consisted of N vertices and some edges. The vertices of the graph were numbered 0 through N-1. Each edge connected a different pair of vertices.

You are given the description of the graph in a vector <string> graph with N elements, each containing N characters. For each i and j, graph[i][j] will be 'Y' if vertex i and vertex j are connected by an edge, and 'N' otherwise. (Note that for each i, graph[i][i] will be 'N': there are no self-loops.)

Lun is interested in articulation pairs in this graph. An articulation pair is an unordered pair of two different vertices whose deletion increases the number of connected components in the graph. (The deletion of a vertex also removes all edges incident with that vertex.)

Return the number of the articulation pairs in Lun's graph.
Definition
    
Class:
Fragile2
Method:
countPairs
Parameters:
vector <string>
Returns:
int
Method signature:
int countPairs(vector <string> graph)
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
You are not given the value of N explicitly, but you can determine it as the number of elements in graph.
-
Two vertices belong to the same connected component if and only if we can reach one of them from the other by following a sequence of zero or more edges.
Constraints
-
graph will contain between 3 and 20 elements, inclusive.
-
Each element of graph will contain N characters, where N is the number of the elements in graph.
-
Each character of each element of graph will be either 'Y' or 'N'.
-
For each valid i and j, graph[i][j] will be equal to graph[j][i].
-
For each valid i, graph[i][i] will be 'N'.
Examples
0)

    
{"NYNN", "YNYN", "NYNY", "NNYN"}
Returns: 3
The graph looks as follows:

 

The articulation pairs are (0, 2), (1, 2) and (1, 3).
For example, here is why (0, 2) is an articulation pair: Currently there is one connected component. (It contains all four vertices.) If we remove the vertices 0 and 2, and all edges incident to these vertices, we will be left with two isolated vertices: 1 and 3. Each of these vertices now forms a different connected component, so the number of connected components increased from 1 to 2.
1)

    
{"NYNNNN", "YNYNNN", "NYNNNN", "NNNNYN", "NNNYNY", "NNNNYN"}
Returns: 5
 

The articulation pairs are (0, 4), (1, 3), (1, 4), (1, 5) and (2, 4).
2)

    
{"NNN", "NNN", "NNN"}
Returns: 0
 

There are no articulation pairs.
3)

    
{"NYNYNNYYNN", "YNNNYNYYNN", "NNNNYNNNYN", "YNNNYYNNNN", "NYYYNNNNYN",
 "NNNYNNNNYN", "YYNNNNNNNN", "YYNNNNNNYN", "NNYNYYNYNY", "NNNNNNNNYN"}
Returns: 9

4)

    
{"NNNYNNYNNNNNNNYYNNNY", "NNNNNNNNYNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNN", "YNNNNNNNNNYNNNNNNNNN", "NNNNNNNYNNNNNYNNNNYN",
 "NNNNNNNNNNNNNNNNYNNY", "YNNNNNNNNNNNNYYYNYNN", "NNNNYNNNNNNNNYYNNNNN", "NYNNNNNNNYNNNNNNNNNN", "NNNNNNNNYNNNYNNNNNYN",
 "NNNYNNNNNNNNNNYNNNNN", "NNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNYNNNNNNNYNN", "NNNNYNYYNNNNNNNNNNNN", "YNNNNNYYNNYNNNNNNNNN",
 "YNNNNNYNNNNNNNNNYNNN", "NNNNNYNNNNNNNNNYNYNN", "NNNNNNYNNNNNYNNNYNNN", "NNNNYNNNNYNNNNNNNNNN", "YNNNNYNNNNNNNNNNNNNN"}
Returns: 42

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

class Fragile2{
public:
	int countPairs(vector <string> graph){
		int N = graph.size();
		int expect=0;
		vector<bool> visited(N,false);
		for(int i=0;i<N;++i){
			if(visited[i]) continue;
			visited[i] = true;
			queue<int> mq;
			mq.push(i);
			while(!mq.empty()){
				int cur = mq.front();
				mq.pop();
				for(int j=0;j<N;++j){
					if(!visited[j]&&graph[cur][j]=='Y'){
						visited[j] = true;
						mq.push(j);
					}
				}
			}
			expect++;
		}
		int res = 0;
		for(int k=0;k<N;++k){
			for(int m=k+1;m<N;++m){
				int group=0;
				vector<bool> used(N,false);
				for(int i=0;i<N;++i){
					if(used[i]||i==k||i==m) continue;
					queue<int> mq;
					mq.push(i);
					used[i] = true;
					while(!mq.empty()){
						int cur = mq.front();
						mq.pop();
						for(int j=0;j<N;++j){
							if(used[j]||j==k||j==m) continue;
							if(graph[cur][j]=='Y'){
								used[j] = true;
								mq.push(j);
							}
						}
					}
					group++;
				}
				if(group>expect) res++;
			}
		}
		return res;
	}
};
