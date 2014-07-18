/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.
*/

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        stack<int> myStack;
        height.push_back(0);
        int n = height.size();
        int Max = height[0];
        for(int i=0;i<n;){
            if(myStack.empty()||height[i]>=height[myStack.top()]) myStack.push(i++);
            else{
                int t = myStack.top();
                myStack.pop();
                Max = max(Max,height[t]*(myStack.empty()?i:i-myStack.top()-1));
            }
        }
        return Max;
    }
};
