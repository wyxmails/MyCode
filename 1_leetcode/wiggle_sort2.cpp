/*
324. Wiggle Sort II My Submissions Question
Total Accepted: 2590 Total Submissions: 13366 Difficulty: Medium
Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example:
(1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6]. 
(2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].

Note:
You may assume all input has valid answer.

Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?
*/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        int l = 0,r=n-1;
        vector<int> tmp = nums;
        int index = partition(tmp,nums,l,r);
        while((index+1)*2<n||(index+1)*2-1>n){
            tmp = nums;
            if((index+1)*2<n){
                l = index+1;
                index = partition(tmp,nums,l,r);
            }else{
                r = index-1;
                index = partition(tmp,nums,l,r);
            }
        }
        int des = nums[index];
        int l1=index,r1=index;
        while(nums[l1]==des) l1--;
        while(nums[r1]==des) r1++;
        int mid = index;
        if(l1<r1){
            int tl = mid,tr=mid+1;
            while(l1>=0){
                nums[tl] = nums[l1];
                tl--;l1--;
            }
            while(tl>=0) nums[tl--] = des;
            while(r1<=n-1){
                nums[tr] = nums[r1];
                tr++;r1++;
            }
            while(tr<=n-1) nums[tr++] = des;
        }
        tmp = nums;
        int i;
        for(i=0;i*2<n;++i){
            nums[2*i] = tmp[i];
        }
        int ss=i;
        for(;i<n;++i){
            nums[(i-ss)*2+1] = tmp[i];
        }
    }
    int partition(vector<int> tmp,vector<int> &nums,int l,int r){
        int des = tmp[l];
        int l1=l,r1=r;
        for(int i=l;i<=r;++i){
            if(tmp[i]>des) nums[r1--] = tmp[i];
            else if(tmp[i]<des) nums[l1++] = tmp[i];
        }
        int mid = l1+(r1-l1)/2;
        while(l1<=r1){
            nums[l1]=nums[r1] = des;
            l1++;r1--;
        }
        return mid;
    }
};
