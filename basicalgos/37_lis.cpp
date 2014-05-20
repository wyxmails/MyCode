#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> find_lis(vector<int> A){
	int n = A.size();
	int mark[n];
	int pre[n];
	for(int i=0;i<n;++i){
		mark[i] = pre[i] = -1;
	}
	mark[0]=0;
	for(int i=1;i<n;++i){
		int j=i-1;
		while(mark[j]<0) j--;
		while(j>=0&&A[i]<A[mark[j]]) j--;
		if(j<0){
			j=0;
			mark[j] = i;
			pre[i] = -1;
			continue;
		}
		if(A[i]==A[mark[j]]) pre[i] = pre[j];
		else{
		   	pre[i] = mark[j];
			mark[j+1] = i;
		}
	}
	vector<int> res;
	res.clear();
	set<int> index;
	index.clear();
	int i=n-1;
	while(mark[i]<0) i--;
	i = mark[i];
	while(i>=0){
		index.insert(A[i]);
		i = pre[i];
	}
	set<int>::iterator it;
	for(it=index.begin();it!=index.end();++it){
		res.push_back(*it);
	}
	return res;
}
int main()
{
	int a[] = { 7, 8, 9, 10, 1, 2, 3, 3, 3, 4, 6, 7, 5, 8}; //14

	vector<int> A; 
	A.assign(a, a+14);
	for(int i=0;i<A.size();++i){
		cout << A[i] << " ";
	}
	cout << endl;
    vector<int> lis = find_lis(A);
	//ostream_iterator<int> oit(cout, " ");
	//copy(lis.begin(), lis.end(), oit);
	for(int i=0;i<lis.size();++i){
		cout << lis[i] << " ";
	}
	cout << endl;	   
	return 0;
}
