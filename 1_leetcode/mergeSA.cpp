/*
Merge Sorted Array Total Accepted: 21389 Total Submissions: 66595 My Submissions
Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.


*/

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i,j;
        for(i=m-1,j=n-1;i>=0&&j>=0;){
            if(A[i]>=B[j]) A[i+j+1] = A[i--];
            else A[i+j+1] = B[j--];
        }
        while(j>=0) A[j] = B[j--];
    }
};
