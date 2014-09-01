#include <iostream>
#include <vector>
using namespace std;
int candy(vector<int> &ratings) {
	// Note: The Solution object is instantiated only once and is reused by each test case.
	int n = ratings.size();
	int arr[n];
	for(int i=0;i<n;++i) arr[i] = 1;
	for(int i=1;i<n;++i){
		if(ratings[i]==ratings[i-1]) continue;
		else if(ratings[i]>ratings[i-1]){
		   	arr[i] = arr[i-1]+1;
			cout << "i: " << i << " arr: " << arr[i] << endl;
			cout << "i-1: " << i-1 << " arr: " << arr[i-1] << endl;
		}else{
			int s = i-1;
			while(i<n&&ratings[i]<ratings[i-1]) i++;
			i--;	
			if(ratings[i]>=ratings[i-1]) i--;
			int e=i-1;
			while(e>=s){
				if(arr[e]<=arr[e+1]) arr[e] = arr[e+1]+1;
				e--;
			}
		}
	}
	int sum = 0;
	for(int i=0;i<n;++i){
	   	sum += arr[i];
	}
	return sum;
}

class Solution {
public:
    int candy(vector<int> &ratings) {
        int n = ratings.size();
        if(n<=1) return n;
        vector<int> mark(n,1);
        for(int i=1;i<n;++i){
            if(ratings[i]>ratings[i-1])
                mark[i] = mark[i-1]+1;
        }
        for(int i=n-2;i>=0;--i){
            if(ratings[i]>ratings[i+1])
                mark[i] = max(mark[i],mark[i+1]+1);
        }
        int res = 0;
        for(int i=0;i<n;++i)
            res += mark[i];
        return res;
    }
};

int main(){
	vector<int> vec;
	vec.clear();
	vec.push_back(4);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(1);
	cout << candy(vec) << endl;
	return 0;
}
