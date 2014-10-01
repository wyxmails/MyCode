/*
 One of the many ways of representing a tree is to have an array(of length same as number of nodes), where each element in the node denotes the parent of that node.
 Eg –
 		0
	   / \
	  1   2
	 / \
	3   4
{-1, 0, 0, 1, 1} would represent a tree with –
* 0 as root
* 1 and 2 as children of 0
* 3 and 4 as children of 1

Given a similar representation, you have to print reverse level order traversal of the corresponding tree.
Level order traversal of a tree is where we traverse levels of tree one by one.

Eg –
For the above given tree, level order traversal would be –
0
1 2
3 4
And hence, the reverse level order traversal is –
3 4
1 2
0
Please note –
* An element with parent = -1 is the root element.
* An element with the least index becomes the left most child. (ie. a node with always be on left of all its siblings that have higher index than it)
* When printing a level of tree you need to maintain left to right order.

Input Format –
First line of the input contains number of nodes in the tree (N)
Next line contains N (space seperated) numbers that denote where i-th number will denote the parent node of i-th node.

Output Format –
Print reverse level order traversal of the corresponding tree, with every new level starting in a different line.
Notes/Limits –
* 1 < = N <= 50
* There will be only one root element in any given test case
* Given numbers will always form a valid undivided tree
* Output should be in the exact format as specified (including whitespaces)
Sample Test Cases -
        0
       / \
      1   2
     /     \
    4       3
input –
5
-1 0 0 2 1
Output –
4 3
1 2
0 
			8
		   / \
		  0   5
		 / \ / \
		2  7 3  4
	      / \
		 1   6
Input –
9
8 7 0 5 5 8 7 0 -1
Output –
1 6
2 7 3 4
0 5
8

Input –
45
24 42 4 30 29 43 22 15 26 36 26 16 3 22 21 41 18 16 34 41 12 29 32 30 43 15 4 38 36 -1 24 42 18 6 21 38 6 17 32 17 3
34 12 14 14
Output –
1 31
20 42 9 28
12 40 33 36
3 23 37 39 6 13 27 35
0 30 11 17 22 38 7 25
5 24 16 32 15 19
8 10 43 44 18 41
2 26 14 34
4 21
29

Input –
33
17 25 0 14 7 2 5 25 18 8 16 27 10 9 19 7 31 31 19 0 8 14 9 17 18 2 30 16 30 10 5 -1 27
Output –
13 22
26 28 4 15 9 20
6 30 1 7 3 21 8 24
5 25 14 18
12 29 11 32 2 19
10 27 0 23
16 17
31
 */


#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;


vector<vector<int> > levelTraverse(int vec[]){
	map<int,vector<int> > tree;
	int n = vec[0];
	for(int i=1;i<=n;++i){
		tree[vec[i]].push_back(i-1);
	}
	vector<vector<int> > res;
	vector<int> tmp;
	res.push_back(tree[-1]);
	int i=0;
	while(i<res.size()){
		tmp.clear();
		for(int j=0;j<res[i].size();++j){
			tmp.insert(tmp.end(),tree[res[i][j]].begin(),tree[res[i][j]].end());
		}
		if(tmp.size()>0) res.push_back(tmp);
		i++;
	}
	reverse(res.begin(),res.end());
	return res;
}

int main(int argc,char*argv[]){
	int arr[] = {5,-1,0,0,2,1};
	vector<vector<int> > res;
	res = levelTraverse(arr);
	cout << "-----arr-----" << endl;
	for(int i=0;i<res.size();++i){
		for(int j=0;j<res[i].size();++j)
			cout << res[i][j] << " ";
		cout << endl;
	}
	cout << "-----arr1-----" << endl;
	int arr1[] = {9,8,7,0,5,5,8,7,0,-1};
	res = levelTraverse(arr1);
	for(int i=0;i<res.size();++i){
		for(int j=0;j<res[i].size();++j)
			cout << res[i][j] << " ";
		cout << endl;
	}
	cout << "-----arr2-----" << endl;
	int arr2[] = {45,24,42,4,30,29,43,22,15,26,36,26,16,3,22,21,41,18,16,34,41,12,29,32,30,43,15,4,38,36,-1,24,42,18,6,21,38,6,17,32,17,3,34,12,14,14};
	res = levelTraverse(arr2);
	for(int i=0;i<res.size();++i){
		for(int j=0;j<res[i].size();++j)
			cout << res[i][j] << " ";
		cout << endl;
	}
	cout << "-----arr3-----" << endl;
	int arr3[]={33,17,25,0,14,7,2,5,25,18,8,16,27,10,9,19,7,31,31,19,0,8,14,9,17,18,2,30,16,30,10,5,-1,27};
	res = levelTraverse(arr3);
	for(int i=0;i<res.size();++i){
		for(int j=0;j<res[i].size();++j)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}
