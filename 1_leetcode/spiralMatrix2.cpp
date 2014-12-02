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

vector<vector<int> > generateMatrix2(int n) {
        vector<vector<int> > res(n,vector<int>(n,0));
        if(n==0) return res;
        int r = (n+1)/2;
        int val=1;
        for(int s=0;s<r;++s){
            for(int j=s;j<n-s;++j) res[s][j] = val++;
            for(int i=s+1;i<n-s;++i) res[i][n-s-1] = val++;
            if(n-s-1!=s){
                for(int j=n-s-2;j>=s;--j) res[n-s-1][j] = val++;
                for(int i=n-s-2;i>s;--i) res[i][s] = val++;
            }
        }
        return res;
}

int main(int argc,char *argv[]){
	return 0;
}
