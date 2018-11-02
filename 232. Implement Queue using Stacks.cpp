/*

*/

class MyQueue {
    stack<int> s1;
    stack<int> s2;
    int size;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        size = 0;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
        size++;
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (s2.empty()) {
            int size = s1.size();
            for (int i=0;i<size;i++) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int res = s2.top();
        s2.pop();
        size--;
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        if (s2.empty()) {
            int size = s1.size();
            for (int i=0;i<size;i++) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return size == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */