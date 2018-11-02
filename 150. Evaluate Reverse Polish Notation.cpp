/*
1，参考了答案，通过递归的方式实现。
2，采用了map通过string，映射到lambda函数的方式，直接实现了逆波兰式的计算。
*/

//version 1(8 ms)
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        string str = tokens.back(); 
        tokens.pop_back();
        if(str != "+" && str != "-" && str != "*" && str != "/") return stoi(str);
        
        int r2 = evalRPN(tokens);
        int r1 = evalRPN(tokens);
        
        if(str == "+") return r1 + r2;
        else if(str == "-") return r1 - r2;
        else if(str == "*") return r1 * r2;
        else return r1 / r2;
    }
};

//version 2(8 ms)
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        map<string, function<int(int,int)>> m = {
            { "+", [] (int a, int b) {return a+b;} },
            { "-", [] (int a, int b) {return b-a;} },
            { "*", [] (int a, int b) {return a*b;} },
            { "/", [] (int a, int b) {return b/a;} }
        };
        for(auto s : tokens) {
            if(!m.count(s)) {
                nums.push(stoi(s));
            } else {
                int a = nums.top();
                nums.pop();
                int b = nums.top();
                nums.pop();
                nums.push(m[s](a,b));
            }
        }
        return nums.top();
    }
};