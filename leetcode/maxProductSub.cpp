/*
Maximum Product Subarray Total Accepted: 2620 Total Submissions: 15050 My Submissions

Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/

struct NP{
    int P;
    int N;
    NP(int n=0,int p=0):N(n),P(p){}
};
class Solution {
public:
    int maxProduct(int A[], int n) {
        if(n==0) return 0;
        if(n==1) return A[0];
        vector<NP> mark(n);
        if(A[0]>=0){
            mark[0].P = A[0];
            mark[0].N = 0;
        }else{
            mark[0].P = 0;
            mark[0].N = A[0];
        }
        int res = A[0];
        for(int i=1;i<n;++i){
            if(A[i]>0){
                if(mark[i-1].P!=0)
                    mark[i].P = mark[i-1].P*A[i];
                else
                    mark[i].P = A[i];
                if(mark[i-1].N!=0)
                    mark[i].N = mark[i-1].N*A[i];
            }else if(A[i]<0){
                if(mark[i-1].P!=0)
                    mark[i].N = mark[i-1].P*A[i];
                else
                    mark[i].N = A[i];
                if(mark[i-1].N!=0)
                    mark[i].P = mark[i-1].N*A[i];
            }
            res = max(res,A[i]);
            if(mark[i].P!=0)
                res = max(res,mark[i].P);
            if(mark[i].N!=0)
                res = max(res,mark[i].N);
        }
        return res;
    }
};
