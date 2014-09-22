#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>&vecL,vector<int>&vecR,vector<int>&vec){
	int i,j,k;
	for(i=0,j=0,k=0;i<vecL.size()&&j<vecR.size();){
		if(vecL[i]<vecR[j])
			vec[k++] = vecL[i++];
		else
			vec[k++] = vecR[j++];
	}
	while(i<vecL.size()) vec[k++] = vecL[i++];
	while(j<vecR.size()) vec[k++] = vecR[j++];
}

void mergeSort(vector<int> &vec){
	int n = vec.size();
	if(n<=1) return;
	vector<int> vecL,vecR;
	vecL.insert(vecL.begin(),vec.begin(),vec.begin()+n/2);
	vecR.insert(vecR.begin(),vec.begin()+n/2,vec.end());
	mergeSort(vecL);
	mergeSort(vecR);
	merge(vecL,vecR,vec);
}

void mergeIte(vector<int>&vec){
	int n = vec.size();
	if(n<=1) return;
	vector<int> tmp;
	for(int s=1;s<n;s*=2){
		for(int j=0;j<n;j+=2*s){
			int k,m;
			tmp.clear();
			for(k=j,m=j+s;k-j<s&&m-j<2*s&&m<n;){
				if(vec[k]<vec[m]) tmp.push_back(vec[k++]);
				else tmp.push_back(vec[m++]);
			}
			while(k-j<s) tmp.push_back(vec[k++]);
			for(k=0,m=j;k<tmp.size();++k,++m)
				vec[m] = tmp[k];
		}
	}
}

int main(int argc,char*argv[]){
	int arr[] = {9,8,2,4,3,5,1,6,7,10};
	vector<int> vec(10);
	for(int i=0;i<10;++i) vec[i] = arr[i];
	for(int i=0;i<10;++i)
		cout << vec[i] << " ";
	cout << endl;
	//mergeSort(vec);
	mergeIte(vec);
	for(int i=0;i<10;++i)
		cout << vec[i] << " ";
	cout << endl;
	return 0;
}
