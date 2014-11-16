/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


*/


class Solution {
public:
    int trap(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int i=0,j=n-1;
        int k;
        int vol = 0;
        while(i<j){
            if(A[i]<A[j]){
                k = i+1;
                while(A[i]>A[k]){
                    vol += A[i]-A[k];
                    k++;
                }
                i=k;
            }else{
                k = j-1;
                while(A[j]>A[k]){
                    vol += A[j]-A[k];
                    k--;
                }
                j = k;
            }
        }
        return vol;
    }
};

class Solution2 {
public:
    int trap(int A[], int n) {
        if(n<=0) return 0;
        int res = 0;
        stack<int> myS;
        for(int i=0;i<n;){
            if(myS.empty()||A[i]<A[myS.top()]) myS.push(i++);
            else{
                int v = A[myS.top()];
                myS.pop();
                if(!myS.empty())
                    res += (i-myS.top()-1)*(min(A[i],A[myS.top()])-v);
            }
        }
        return res;
    }
};

class Solution {
public:
    int trap(int A[], int n) {
        vector<int> mark(n,0);
        int M=0;
        for(int i=0;i<n;++i){
            mark[i] = M;
            M = max(M,A[i]);
        }
        M = 0;
        for(int i=n-1;i>=0;--i){
            mark[i] = min(mark[i],M);
            M = max(M,A[i]);
        }
        int res = 0;
        for(int i=0;i<n;++i){
            res += mark[i]>A[i]?mark[i]-A[i]:0;
        }
        return res;
    }
};
