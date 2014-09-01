/*
Sort Colors Total Accepted: 21545 Total Submissions: 67290 My Submissions
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?

*/

class Solution {
public:
    void sortColors(int A[], int n) {
        int l=-1,r=n,m=0;
        while(m<r&&l<r){
            if(A[m]==0){
                l++;
                int tmp = A[m];
                A[m] = A[l];
                A[l] = tmp;
            }else if(A[m]==2){
                r--;
                int tmp = A[m];
                A[m] = A[r];
                A[r] = tmp;
            }
            if(m==l||A[m]==1) m++;
        }
    }
};
