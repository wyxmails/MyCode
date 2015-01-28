/*
 You have an array with n elements. The elements are either 0 or 1. You want to split the array into k contiguous subarrays. The size of each subarray can vary between ceil(n/2k) and floor(3n/2k). You can assume that k << n. After you split the array into k subarrays. One element of each subarray will be randomly selected.

 Devise an algorithm for maximizing the sum of the randomly selected elements from the k subarrays. Basically means that we will want to split the array in such way such that the sum of all the expected values for the elements selected from each subarray is maximum.

 You can assume that n is a power of 2.
Example:

Array: [0,0,1,1,0,0,1,1,0,1,1,0]
n = 12
k = 3
Size of subarrays can be: 2,3,4,5,6

Possible subarrays [0,0,1] [1,0,0,1] [1,0,1,1,0]
Expected Value of the sum of the elements randomly selected from the subarrays: 1/3 + 2/4 + 3/5 = 43/30 ~ 1.4333333 

Optimal split: [0,0,1,1,0,0][1,1][0,1,1,0]
Expected value of optimal split: 1/3 + 1 + 1/2 = 11/6 ~ 1.83333333
 */

#include <iostream>
#include <vector>
using namespace std;


double count(const vector<int> &vec,int l,int r){
	if(l>r) return 0;
	int ones=0;
	for(int i=l;i<=r;++i)
		if(vec[i]==1) ones++;
	return (double)ones/double(r+1-l);
}

double myCom(const vector<int>&vec,int cur,int len,int k,int len1,int len2){
	if(cur>=len&&k>0) return -1;
	if(cur<len&&k==0) return -1;
	if(k==1&&len-cur>=len1&&len-cur<=len2){
		return count(vec,cur,len-1);
	}
	double res=-1;
	for(int i=len1;cur+i<len&&i<=len2;++i){
		double mid = myCom(vec,cur+i,len,k-1,len1,len2);
		if(mid!=-1){
			if(res==-1) res = mid+count(vec,cur,cur+i-1);
			else res = max(res,mid+count(vec,cur,cur+i-1));
		}
	}
	return res;
}

double CombiOpt(vector<int> vec,int k){
	int n = vec.size();
	int len1 = n/(2*k),len2 = (3*n)/(2*k);
	double res = -1;
	return myCom(vec,0,n,k,len1,len2);
}

int main(int argc,char*argv[]){
	int arr[] = {0,0,1,1,0,0,1,1,0,1,1,0};
	vector<int> vec;
	for(int i=0;i<sizeof(arr)/sizeof(arr[0]);++i)
		vec.push_back(arr[i]);
	cout << CombiOpt(vec,3) << endl;
	return 0;
}
