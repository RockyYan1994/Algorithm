/*
	方法一：在pop的时候是O(n)，主要通过t和size来减少判断。而pop需要通过便利一次队列。
	方法二：在push的时候是O(n)。
*/

class MyStack {
    queue<int> q;
    int size;
    int t;
public:
    /** Initialize your data structure here. */
    MyStack() {
        size = 0;
        t = 0;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        size++;
        t = x;        
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        for(int i=0;i<q.size()-1;i++) {
            int temp = q.front();
            if(q.size()-2 == i) t = temp;
            q.pop();
            q.push(temp);            
        }
        int res = q.front();
        q.pop();
        size--;
        return res;
    }
    
    /** Get the top element. */
    int top() {
        if (size == 0) return -1;
        return this->t;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return size == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */

//version 2()
class MyStack {
    queue<int> q;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        for(int i=0;i<q.size()-1;i++) {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int temp = q.front();
        q.pop();
        return temp;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};