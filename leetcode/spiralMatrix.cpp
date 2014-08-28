#include <iostream>
#include <vector>
using namespace std;
/*
 Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 
 For example,
 Given the following matrix:
 
 [
  [ 1, 2, 3 ],
  [ 4, 5, 6 ],
  [ 7, 8, 9 ]
 ]
 You should return [1,2,3,6,9,8,7,4,5].
 */
vector<int> mySpi(vector<vector<int> > &matrix,int s,int m,int n){
	vector<int> res;
	res.clear();
	if(2*s>=n||2*s>=m) return res;
	for(int i=s;i<n-s;++i)
		res.push_back(matrix[s][i]);
	for(int i=s+1;i<m-s;++i)
		res.push_back(matrix[i][n-s-1]);
	if(m-s-1!=s)
		for(int i=n-s-2;i>=s;--i)
			res.push_back(matrix[m-s-1][i]);
	if(n-s-1!=s)
		for(int i=m-s-2;i>s;--i)
			res.push_back(matrix[i][s]);
	vector<int> sub;
	sub.clear();
	sub = mySpi(matrix,s+1,m,n);
	res.insert(res.end(),sub.begin(),sub.end());
	return res;
}
vector<int> spiralOrder(vector<vector<int> > &matrix) {
	vector<int> res;
	int m = matrix.size();
	if(m==0) return res;
	int n = matrix[0].size();
	return mySpi(matrix,0,m,n);
}

vector<int> spiralOrder2(vector<vector<int> > &matrix) {
        vector<int> res;
        int m = matrix.size();
        if(m==0) return res;
        int n = matrix[0].size();
        if(n==0) return res;
        int r = min(m+1,n+1)/2;
        for(int s=0;s<r;++s){
            for(int j=s;j<n-s;++j) res.push_back(matrix[s][j]);
            for(int i=s+1;i<m-s;++i) res.push_back(matrix[i][n-s-1]);
            if(m-s-1!=s)
                for(int j=n-s-2;j>=s;--j) res.push_back(matrix[m-s-1][j]);
            if(n-s-1!=s)
                for(int i=m-s-2;i>s;--i) res.push_back(matrix[i][s]);
        }
        return res;
}

int main(int argc,char*argv[]){
	vector<int> vec;
	vec.push_back(2);
	vec.push_back(3);
	vector<vector<int> > vec1;
	vec1.push_back(vec);
	vector<int> res = spiralOrder(vec1);
	for(int i=0;i<res.size();++i){
		cout << res[i] << endl;
	}
	return 0;
}
