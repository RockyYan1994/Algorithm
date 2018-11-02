/*
	方法一：在push的时候同时维护一个最小栈，比较x是否比最小栈顶更小。pop的时候同时pop两个栈的元素。
	方法二：在push的时候判定，如果小于或者等于则push进入最小栈，否则就不push。出栈的时候就判定是否等于最小栈的top
	等于就pop。
*/

//version 1(18 ms)
class MinStack {
public:
    stack<int> s;
    stack<int> minStack;
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        if(minStack.empty()) minStack.push(x);
        else minStack.push(x<minStack.top()?x:minStack.top());
    }
    
    void pop() {
        s.pop();
        minStack.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};