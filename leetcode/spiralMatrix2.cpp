#include <iostream>
#include <vector>
using namespace std;
/*
 Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
 
 For example,
 Given n = 3,
 
 You should return the following matrix:
 [
  [ 1, 2, 3 ],
  [ 8, 9, 4 ],
  [ 7, 6, 5 ]
 ]
 */
void myGen(vector<vector<int> > &vec,int s,int index,int n){
	if(2*index>=n) return ;
	for(int i=index;i<n-index;++i) vec[index][i] = s++;
	for(int i=index+1;i<n-index;++i) vec[i][n-index-1] = s++;
	if(n-index-1!=index){
		for(int i=n-index-2;i>=index;--i) vec[n-index-1][i] = s++;
		for(int i=n-index-2;i>index;--i) vec[i][index] = s++;
	}
	myGen(vec,s,index+1,n);
}
vector<vector<int> > generateMatrix(int n) {
	vector<vector<int> > res;
	vector<int> tmp;
	for(int i=0;i<n;++i) tmp.push_back(0);
	for(int i=0;i<n;++i) res.push_back(tmp);
	myGen(res,1,0,n);
	return res;
}
int main(int argc,char *argv[]){
	return 0;
}
