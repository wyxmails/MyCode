/*
 Find Minimum in Rotated Sorted Array II Total Accepted: 6942 Total Submissions: 24386 My Submissions Question Solution 
 Follow up for "Find Minimum in Rotated Sorted Array":
 What if duplicates are allowed?

 Would this affect the run-time complexity? How and why?
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.

 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

 Find the minimum element.

 The array may contain duplicates.
 */
class Solution {
public:
	int findMin(vector<int> &num) {
		int l=0,r = num.size()-1;
		while(l<r){
			int m = (l+r)/2;
			int ml=m,mr=m;
			while(ml>l&&num[ml]==num[m]) ml--;
			while(mr<r&&num[mr]==num[m]) mr++;
			if(num[m]<num[ml]&&num[m]<num[mr])
				return num[m];
			else if(num[m]<num[r]&&num[m]<num[l]) r = ml;
			else if(num[m]>num[r]&&num[m]>num[l]) l = mr;
			else{
				if(num[l]>num[r]) l++;
				else r--;
			}
		}
		return num[l];
	}
};
