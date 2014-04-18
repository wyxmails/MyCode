#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int maximalRectangle(vector<vector<char> > &matrix) {
	// Note: The Solution object is instantiated only once and is reused by each test case.
	int m = matrix.size();
	if(m==0) return 0;
	int n = matrix[0].size();
	if(n==0) return 0;
	int mark[m+1][n];
	for(int i=0;i<m;++i) mark[i][0] = (int)(matrix[i][0]-'0');
	for(int j=0;j<n;++j) mark[m][j] = 0;
	for(int i=0;i<m;++i){
		for(int j=1;j<n;++j){
			if(matrix[i][j]!='0') mark[i][j] = mark[i][j-1]+1;
			else mark[i][j] = 0;
		}
	}
	int M=0;
	for(int j=0;j<n;++j){
		stack<int> ms;
		int mm=0;
		for(int i=0;i<=m;){
			if(ms.empty()||mark[i][j]>=mark[ms.top()][j]){
			   	ms.push(i++);
			}else{
				int t = ms.top();
				ms.pop();
				mm = max(mm,mark[t][j]*(ms.empty()?i:i-ms.top()-1));
			}
		}
		M = max(M,mm);
	}
	return M;
}
int main(){
	vector<vector<char> > test;
	vector<char> vec;
	vec.push_back('1');
	test.push_back(vec);
	cout << maximalRectangle(test) << endl;
	return 0;
}
