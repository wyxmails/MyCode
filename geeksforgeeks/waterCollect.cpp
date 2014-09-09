/*
 You are given an array whose each element represents the height of the tower. The width of every tower is 1. It starts raining. How much water is collected between the towers?
 Eg. [1,5,3,7,2] – then answer is 2 units between towers 5 and 7.
 Eg. [5,3,7,2,6,4,5,9,1,2] – then answer is 14 units = 2 (between towers 5 and 7)+4(b/w 7 and 6)+1(b/w 6 and 5)+2(b/w 6 and 9)+4(b/w 7 and 9)+1(b/w 9 and 2).
 We have to write a code and explain the algorithm to implement this.
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int waterCollect(vector<int> towers){
	int n = towers.size();
	if(n<=2) return 0;
	stack<int> myS;
	int res = 0;
	for(int i=0;i<n;){
		if(myS.empty()||towers[i]<=towers[myS.top()]) myS.push(i++);
		else{
			int tmp = towers[myS.top()];
			myS.pop();
			if(!myS.empty())
				res += (min(towers[i],towers[myS.top()])-tmp)*(i-myS.top()-1);
		}
	}
	return res;
}
int main(int argc,char*argv[]){
	vector<int> vec;
	vec.push_back(5);vec.push_back(3);
	vec.push_back(7);vec.push_back(2);
	vec.push_back(6);vec.push_back(4);
	vec.push_back(5);vec.push_back(9);
	vec.push_back(1);vec.push_back(2);
	cout << waterCollect(vec) << endl;
	return 0;
}
