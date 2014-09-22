#include <iostream>
#include <vector>
using namespace std;

int findRotate(const vector<int> &vec,int target){
		int l=0,r=vec.size()-1;
		while(l<=r){
			int m = (l+r)/2;
			if(vec[m]==target){
				return m;
			}else if(vec[l]<vec[m]){
				if(vec[m]>target) r = m-1;
				else l = m+1;
			}else if(vec[r]>vec[m]){
				if(vec[m]<target) l = m+1;
				else r = m-1;
			}else{
				if(vec[l]==target) return l;
				l++;
			}
		}
		return -1;
}

int main(int argc,char*argv[]){
	vector<int> vec(12,0);
	int arr[] = {15,16,19,20,25,1,3,4,5,7,10,14};
	for(int i=0;i<12;++i)
		vec[i] = arr[i];
	cout << findRotate(vec,5) << endl;
	return 0;
}
