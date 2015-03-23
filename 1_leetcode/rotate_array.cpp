/*
Rotate Array Total Accepted: 13588 Total Submissions: 77822 My Submissions Question Solution 
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

[show hint]

Related problem: Reverse Words in a String II
*/

class Solution {
public:
    void rotate(int nums[], int n, int k) {
        int tmp[n];
        for(int i=0;i<n;++i)
            tmp[i] = nums[i];
        k %= n;
        for(int i=0;i<n;++i){
            nums[i] = tmp[(i+n-k)%n];
        }
        return;
    }
};
