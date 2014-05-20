#include <iostream>
#include <vector>
#include <climits>
#include <set>
using namespace std;

struct Matrix
{
    Matrix(int _m, int _n) : m(_m), n(_n){}
    int m;
    int n;
};

vector<vector<int> > matrix_chain_order(vector<Matrix> A){
	int n = A.size();
	vector<vector<int> > vecmark(n,vector<int>(n,0));
	vector<vector<int> > s(n,vector<int>(n,0));
	int i,j,k,L;
	for(i=0;i<n;++i) vecmark[i][i] = 0;
	for(L=2;L<=n;++L){
		for(i=0;i<=n-L;++i){
			j=i+L-1;
			vecmark[i][j] = INT_MAX;
			for(k=i;k<j;++k){
				int cost = vecmark[i][k] + vecmark[k+1][j] + A[i].m*A[k].n*A[j].n;
				if(cost<vecmark[i][j]){
					vecmark[i][j] = cost;
					s[i][j] = k;
				}
			}
		}
	}
	return s;
}
set<int> printPar(vector<vector<int> > s,int L,int R){
	set<int> ss,ss1,ss2;
	ss.clear();
	ss1.clear();
	ss2.clear();
	if((R-L)<=1) return ss;
	ss.insert(s[L][R]);
	ss1 = printPar(s,L,s[L][R]);
	ss2 = printPar(s,s[L][R]+1,R);
	ss.insert(ss1.begin(),ss1.end());
	ss.insert(ss2.begin(),ss2.end());
	return ss;
}
int main()
{
    Matrix A1(30, 35), A2(35,15), A3(15, 5), A4(5, 10);
    Matrix A5(10, 20), A6(20, 25);

    vector<Matrix> A;
    A.push_back(A1);
    A.push_back(A2);
    A.push_back(A3);
    A.push_back(A4);
    A.push_back(A5);
    A.push_back(A6);
	for(int i=0;i<A.size();++i){
			cout << A[i].m << " " << A[i].n << endl;
	}	
    vector<vector<int> > s = matrix_chain_order(A);
	set<int> ss = printPar(s,0,s.size()-1);
	set<int>::iterator it;
	cout << "result: " << endl;
	for(it=ss.begin();it!=ss.end();++it){
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}
