/*
 An operation “swap” means removing an element from the array and appending it at the back of the same array. Find the minimum number of “swaps” needed to sort that array.
 
Eg :- 3124
 
Output: 2 (3124->1243->1234)
 
 How to do it in less than O(n^2) ? 
 */
/*solution
 sort the array O(nlogn)
 and then find the ascending subsequence from the minium value,
 the ascending subsequence must be adjacent in the sorted array,
 but intervals of other value is accepted
	exp:5-1-3-2-4,subsequence is 1-2, 4 is not in the sequence 
		5-4-1-3-2, subsequence is 1-2
swaps will not be more than n-1, because at least the minimum value itself is a subsequence. So, the initial result value is n, and then minus the subsequence's length.
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

int findMinSwap(vector<int> &vec){
	int n = vec.size();
	if(n<=1) return 0;
	vector<int> vectmp = vec;
	sort(vectmp.begin(),vectmp.end());
	int len=0;
	for(int i=0;i<n;++i){
		if(vec[i]==vectmp[len]) len++;
	}
	return n-len;
}

int main(int argc,char*argv[]){
	vector<int> vec;
	//vec.push_back(3); vec.push_back(1);
	//vec.push_back(2); vec.push_back(4);
	srand(time(NULL));
	for(int i=0;i<5;++i){
		int tmp = rand()%10;
		vec.push_back(tmp);
		cout << tmp << " ";
	}
	cout << endl;
	cout << findMinSwap(vec) << endl;
	return 0;
}
