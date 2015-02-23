/*

Problem Statement
    
You live in the Kingdom of Byteland. The kingdom has a very interesting history. It has already existed for h years. During the first year of its existence the inhabitants built the first city. During each of the next h-1 years the following procces occurred: For each city built in the previous year, two additional cities were built and the older city was connected to each the two new cities by a bidirecional road. Now, after h full years, the kingdom contains exactly (2^h)-1 cities and (2^h)-2 roads.

Recently the King did two changes to the kingdom. First, he numbered the cities from 1 to (2^h)-1 in an arbitrary way. Then, he added exactly one new road to the kingdom. (The road could have connected two cities that were already connected by a different road. Also, it is possible that the new road connected some city to itself.)

You are given the int h and two vector <int>s a and b with (2^h)-1 elements each. For each valid i, there is a road between the cities a[i] and b[i].

Return "Correct" if it is possible that the given list of roads is the current road network in the Kingdom of Byteland. Otherwise, return "Incorrect".
Definition
    
Class:
TheKingsRoadsDiv2
Method:
getAnswer
Parameters:
int, vector <int>, vector <int>
Returns:
string
Method signature:
string getAnswer(int h, vector <int> a, vector <int> b)
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
h will be between 2 and 10, inclusive.
-
a and b will contain exactly (2^h)-1 elements each.
-
Each element of a and b will be between 1 and (2^h)-1, inclusive.
Examples
0)

    
3
{1, 2, 3, 7, 1, 5, 4}
{6, 7, 4, 3, 3, 1, 7}
Returns: "Correct"
City 3 was built during the first year, cities 1 and 7 during the second year, and the other four cities during the third year. Then the King added the road 3-4.
1)

    
2
{1, 2, 3}
{2, 1, 3}
Returns: "Incorrect"

2)

    
3
{7, 1, 1, 2, 2, 3, 1}
{7, 1, 7, 4, 5, 2, 6}
Returns: "Incorrect"

3)

    
2
{1, 3, 3}
{2, 1, 2}
Returns: "Correct"

4)

    
3
{6, 5, 3, 3, 5, 5, 6}
{1, 5, 5, 6, 4, 7, 2}
Returns: "Correct"
Here the road added by the King is obviously the self-loop from city 5 to itself.
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class TheKingsRoadsDiv2{
public:
	string getAnswer(int h, vector <int> a, vector <int> b){
		string yes("Correct"),no("Incorrect");
		bool self = false;
		bool dup = false;
		int n = a.size();
		int node = (1<<h)-1;
		vector<vector<int> > mark(node+1);
		for(int i=0;i<n;++i){
			if(a[i]==b[i]){
				if(self) return no;
				self = true;
			}else{
				if(count(mark[a[i]].begin(),mark[a[i]].end(),b[i])>0){
					if(dup) return no;
					dup = true;
				}else{
					mark[a[i]].push_back(b[i]);
					mark[b[i]].push_back(a[i]);
				}
			}
		}

		if(self&&dup) return no;
		if(self||dup){
			if(check(mark,node,h)) return yes;
		}else{
			for(int i=0;i<n;++i){
				vector<vector<int> > tmp = mark;
				tmp[a[i]].erase(find(tmp[a[i]].begin(),tmp[a[i]].end(),b[i]));
				tmp[b[i]].erase(find(tmp[b[i]].begin(),tmp[b[i]].end(),a[i]));
				if(check(tmp,node,h)) return yes;
			}
		}
		return no;
	}
	bool check(vector<vector<int> > mark,int node,int h){
		vector<bool> visited(node+1,false);
		int leaf = (1<<(h-1)),inner=0,root=1;
		vector<int> one;
		for(int i=1;i<=node;++i){
			if(mark[i].size()==2){ 
				one.push_back(i);
				visited[i] = true;
			}
		}
		if(one.size()!=root) return false;
		int height=1;
		while(height<h){
			height++;
			int expect = 3;
			if(h==height) expect = 1;
			vector<int> second;
			for(int i=0;i<one.size();++i){
				int cur = one[i];
				for(int j=0;j<mark[cur].size();++j){
					int nn = mark[cur][j];
					if(!visited[nn]){
						if(mark[nn].size()!=expect) return false;
						second.push_back(nn);
						visited[nn] = true;
					}
				}
			}
			if(second.size()!=one.size()*2) return false;
			if(h==height){
				if(second.size()!=leaf) 
					return false;
			}else inner += second.size();
			swap(second,one);
		}
		for(int i=1;i<=node;++i)
			if(!visited[i]) return false;
		if(inner!=(node-root-leaf)) return false;
		return true;
	}
};
