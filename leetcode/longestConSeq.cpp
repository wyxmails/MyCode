#include <iostream>
#include <vector>
using namespace std;
/*Given an unsorted array of integers, 
* find the length of the longest consecutive elements sequence.
* For example,
* Given [100, 4, 200, 1, 3, 2],
* The longest consecutive elements sequence is [1, 2, 3, 4]. 
* Return its length: 4.
* 
* Your algorithm should run in O(n) complexity.
*/
int longestConsecutive(vector<int> &num) {
	vector<int> arr[19];
	for(int i=1;i<10;++i){
		for(int j=0;j<19;++j) arr[j].clear();
		for(int j=0;j<num.size();++j){
			int p = pow(10,i-1);
			int tmp = (num[j]/p)%10+9;
			arr[tmp].push_back(num[j]);
		}
		num.clear();
		for(int j=0;j<19;++j){
			num.insert(num.end(),arr[j].begin(),arr[j].end());
		}
	}
	int Max = 1;
	int s = 0;
	int i;
	for(i=1;i<num.size();++i){
		if(num[i]-num[i-1]>1){
			if((i-s)>Max) Max = i-s;
			s = i;
		}
		if(num[i]==num[i-1]) s++;
	}
	if(i-s>Max) return i-s;
	return Max;
}
int main(int argc,char*argv[]){
	return 0;
}
