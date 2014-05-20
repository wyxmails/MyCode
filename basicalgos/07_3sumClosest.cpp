#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

int threeClos(vector<int>&num,int target){
	unsigned int MIN= (unsigned int)(1<<31)-1;
	int tmp;
	sort(num.begin(),num.end());
	for(int i=0;i<num.size()-2;++i){
		for(int j=i+1,k=num.size()-1;j<k;){
			tmp = num[i]+num[j]+num[k]-target;
			if(tmp==0){
				MIN = tmp;
				return MIN;
			}else if(tmp>0){
				if(tmp<MIN) MIN = tmp;
				else k--;
			}else{
				tmp = -tmp;
				if(tmp<MIN) MIN = tmp;
				else j++;
			}
		}
	}
	return MIN;
}
int main(){
	vector<int> num;
	num.clear();
	int n;
	cin>>n;
	srand(time(0));
	for(int i=0;i<n;++i){
		num.push_back(rand()%(n*5));
		cout << num[i] << " ";
	}
	cout << endl;
	int target = n*6;
	cout << "target: " << n*6 << endl;
	cout << threeClos(num,target) << endl;
	return 0;
}
