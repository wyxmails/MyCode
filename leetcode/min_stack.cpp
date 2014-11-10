/*
Min Stack Total Accepted: 1315 Total Submissions: 7921 My Submissions Question Solution 
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Hide Tags: Stack Data Structure

*/
class MinStack {
public:
    void push(int x) {
        if(S2.empty()||x<=S2.top()) S2.push(x);
        S1.push(x);
    }

    void pop() {
        if(S1.empty()) return;
        if(S2.top()==S1.top()) S2.pop();
        S1.pop();
    }

    int top() {
        return S1.top();
    }

    int getMin() {
        return S2.top();
    }
private:
    stack<int> S1;
    stack<int> S2;
};
