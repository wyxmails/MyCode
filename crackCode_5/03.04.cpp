/*
 In the classic problem of the Towers of Hanoi, 
 you have 3 towers and N disks of different sizes which can slide onto any tower. 
 The puzzle starts with disks sorted in ascending order of size from top to bottom 
 (i.e., each disk sits on top of an even larger one). 
 You have the following constraints:
 (1) Only one disk can be moved at a time.
 (2) A disk is slid off the top of one tower onto the next rod.
 (3) A disk can only be placed on top of a larger disk.
 Write a program to move the disks from the first tower to the last using Stacks.
 */

#include <iostream>
#include <stack>
using namespace std;

void Hanoi(int n,stack<int>& tower1,stack<int>& tower2,stack<int>& tower3){
	if(tower1.size()<n) return;
	if(n<=0) return;
	Hanoi(n-1,tower1,tower3,tower2);
	tower3.push(tower1.top());
	tower1.pop();
	Hanoi(n-1,tower2,tower1,tower3);
}

int main(int argc,char*argv[]){
	stack<int> s1,s2,s3;
	int n=5;
	for(int i=n;i>0;--i) s1.push(i);
	Hanoi(n,s1,s2,s3);
	while(!s3.empty()){
		cout << s3.top() << " ";
		s3.pop();
	}
	cout << endl;
	return 0;
}
