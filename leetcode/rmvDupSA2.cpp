/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].
*/

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int cnt = 1;
        if(n<=2) return n;
        int e = 1;
        for(int i=1;i<n;++i){
            if(A[i]==A[i-1]){
                if(cnt<2){
                    cnt++;
                    A[e++] = A[i];
                }
            }else{
                cnt = 1;
                A[e++] = A[i];
            }
        }
        return e;
    }
};
