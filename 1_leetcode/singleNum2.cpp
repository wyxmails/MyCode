#include <iostream>
using namespace std;
int singleNumber(int A[], int n) {
	// IMPORTANT: Please reset any member data you declared, as
	// the same Solution instance will be reused for each test case.
	int len = sizeof(int)*8+2;
	int arr[len];
	for(int i=0;i<len;++i) arr[i]=0;
	unsigned int num;
	for(int i=0;i<n;++i){
		num = A[i];
		int cnt=0;
		while(num){
			cout << num << endl;
			if(num&1) arr[cnt]++;
			cout << "arr[" << cnt << "]: " << arr[cnt] << endl;
			cnt++;
			num >>=1;
		}
	}
	int tmp = 0;
	for(int i=len-1;i>=0;--i){
		if(arr[i]%3){
		   	tmp |= 1<<i;
			cout <<"i: " << i << endl;
		}
	}
	return tmp;
}

class Solution {
public:
    int singleNumber(int A[], int n) {
        vector<int> vec(32,0);
        for(int i=0;i<n;++i){
            for(int j=0;j<32;++j){
                if((1<<j)&A[i]){
                    vec[j]++;
                }
            }
        }
        int res = 0;
        for(int i=0;i<32;++i){
            if(vec[i]%3) res |= (1<<i);
        }
        return res;
    }
};

int main(){
	//int arr[10] = {-2,-2,1,1,-3,1,-3,-3,-4,-2};
	int arr[4] = {2,2,3,2};
	cout << singleNumber(arr, 4) << endl;
	return 0;
}
