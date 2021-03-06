#include <iostream>
#include <string>
#include <vector>
using namespace std;
string getPermutation(int n, int k) {
	// IMPORTANT: Please reset any member data you declared, as
	// the same Solution instance will be reused for each test case.
	int amount = 1;
	vector<int> vec;
	for(int i=1;i<10;++i) vec.push_back(i);
	for(int i=1;i<n;++i) amount *= i;
	string res = "";
	for(int i=n;i>0;--i){
		if(k<=amount){
			res += char('0'+vec[n-i]);
			if(i>1){
				amount /= i-1;
			}
		}else{
			int tmp = (k-1)/amount;
			res += char('0'+vec[n-i+tmp]);
			vec.erase(vec.begin()+n-i+tmp);
			vec.insert(vec.begin(),0);
			k -= tmp*amount;
			if(i>1) amount /= i-1;
		}
	}

	return res;
}

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        for(int i=0;i<n;++i) nums.push_back(i+1);
        int m=1;
        for(int i=1;i<=n;++i) m*=i;
        string res = "";
        k--;
        for(int i=0;i<n;++i){
            m /= (n-i);
            int index = k/m;
            res += char(nums[index]+'0');
            for(int j=index;j<n-i;++j) nums[j] = nums[j+1];
            k = k%m;
            
        }
        return res;
    }
};

int main(){
	int n,k;
	cin>>n>>k;
	cout << getPermutation(n,k) << endl;
	return 0;
}
