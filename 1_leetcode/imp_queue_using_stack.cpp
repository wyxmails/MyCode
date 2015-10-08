/*
Implement Queue using Stacks My Submissions Question Solution 
Total Accepted: 19146 Total Submissions: 56530 Difficulty: Easy
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Notes:
You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
Hide Tags Stack Design
Hide Similar Problems (E) Implement Stack using Queues
*/

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        S1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(S2.empty()) {
            while(!S1.empty()){
                S2.push(S1.top());
                S1.pop();
            }
        }
        S2.pop();
    }

    // Get the front element.
    int peek(void) {
        if(S2.empty()){
            while(!S1.empty()){
                int tmp = S1.top();
                S2.push(tmp);
                S1.pop();
            }
        }
        return S2.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return S1.empty()&&S2.empty();
    }
private:
    stack<int> S1;
    stack<int> S2;
};
