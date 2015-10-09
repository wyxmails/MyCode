/*
Implement Stack using Queues My Submissions Question Solution 
Total Accepted: 19412 Total Submissions: 63739 Difficulty: Easy
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Notes:
You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, 
and is empty operations are valid.
Depending on your language, queue may not be supported natively. 
You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
Update (2015-06-11):
The class name of the Java function had been updated to MyStack instead of Stack.
*/

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        q1.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        queue<int> tmp = q1;
        q1 = q2;
        q2 = tmp;
    }

    // Get the top element.
    int top() {
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }
        int v = q1.front();
        q1.pop();
        q2.push(v);
        queue<int> tmp = q1;
        q1 = q2;
        q2 = tmp;
        return v;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty()&&q2.empty();
    }
private:
    queue<int> q1;
    queue<int> q2;
};
