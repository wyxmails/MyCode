/*
Find the Duplicate Number My Submissions Question Solution 
Total Accepted: 5982 Total Submissions: 17918 Difficulty: Hard
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size()-1;
        int left=1,right=n;
        while(left<right){
            int res = left+(right-left)/2;
            int count=0;
            for(int i=0;i<=n;++i){
                if(nums[i]<=res)
                    count++;
            }
            if(count>res) right = res;
            else left = res+1;
        }
        return left;
    }
};

/*a great problem and perfect solution*/
class Solution1 {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0,fast=0;
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);
        int finder = 0;
        do{
            slow = nums[slow];
            finder = nums[finder];
        }while(slow!=finder);
        return slow;
    }
};
