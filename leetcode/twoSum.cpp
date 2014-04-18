/*
   Given an array of integers, 
   find two numbers such that they add up to a specific target number.
   The function twoSum should return indices of the two numbers 
   such that they add up to the target, 
   where index1 must be less than index2. 
   Please note that your returned answers 
   (both index1 and index2) are not zero-based.
   You may assume that each input would have exactly one solution.
   Input: numbers={2, 7, 11, 15}, target=9 
   Output: index1=1, index2=2
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;
vector<int> twoSum(vector<int> &numbers, int target) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	vector<int>::iterator it1,it2;
	bool match = false;
	it1 = numbers.begin();
	it2--;
	int i1,i2;
	i1 = 1;
	while(!match&&it1!=numbers.end()){
		it2 = it1;
		it2++;
		i2 = i1+1;
		while(!match&&it2!=numbers.end()){
			if((*it1+*it2)==target) match = true;
			else{
				i2++;
				it2++;
			}
		}
		if(!match){
			it1++;
			i1++;
		}
	}
	vector<int> index;
	index.clear();
	index.push_back(i1);
	index.push_back(i2);
	return index;
}
int main(){
	int n,target,tmp;
	vector<int> nums;
	nums.clear();
	cin>>n;
	srand(time(0));
	tmp = 0;
	for(int i=0;i<n;++i){
		tmp += rand()%n+1;
		nums.push_back(tmp);
		cout << tmp << " ";
	}
	cout << endl;
	target = nums[rand()%n] + nums[rand()%n];
	cout << target << endl;
	vector<int> index;
	index.clear();
	index = twoSum(nums,target);
	cout << index[0] << " " << index[1] << endl;
	return 0;
}
