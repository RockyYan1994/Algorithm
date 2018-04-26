/*
定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
感觉这个min函数的意思是返回当前的栈内的最小值，看discussion中大多数的实现都是采用两个栈实现，一个辅助栈来维持最小值。直接搬运的结果，没有实现。
*/


链接：https://www.nowcoder.com/questionTerminal/4c776177d2c04c2494f2555c9fcc1e49
来源：牛客网

class Solution {
public:
     
    stack<int> stack1,stack2;
     
    void push(int value) {
        stack1.push(value);
        if(stack2.empty())
            stack2.push(value);
        else if(value<=stack2.top())
        {
            stack2.push(value);
        }
    }
     
    void pop() {
        if(stack1.top()==stack2.top())
            stack2.pop();
        stack1.pop();
         
    }
     
    int top() {
        return stack1.top();       
    }
     
    int min() {
        return stack2.top();
    }
     
};