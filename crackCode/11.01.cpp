#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge2Arr(vector<int> &A1,const vector<int>& A2){
	int n = A1.size();
	int m = A2.size();
	int run = n-1;
	n -= m; n--;m--;
	while(n>=0&&m>=0){
		if(A1[n]>=A2[m]) A1[run--] = A1[n--];
		else A1[run--] = A2[m--];
	}
	while(m>=0) A1[run--] = A2[m--];
}

int main(int argc,char*argv[]){
	vector<int> vec1(10);
	vector<int> vec2(3);
	srand(time(NULL));
	for(int i=0;i<7;++i){
		int tmp = rand()%20;   
		vec1[i] = tmp;
		cout << tmp << " ";
	}
	for(int i=0;i<3;++i){
		int tmp = rand()%20;   
		vec2[i] = tmp;
		cout << tmp << " ";
	}
	cout << endl;
	sort(vec1.begin(),vec1.end()-3);
	sort(vec2.begin(),vec2.end());
	merge2Arr(vec1,vec2);
	for(int i=0;i<10;++i)
		cout << vec1[i] << " ";
	cout << endl;
	return 0;
}
