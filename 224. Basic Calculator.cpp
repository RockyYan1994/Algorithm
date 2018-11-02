/*
	方法一：把这个问题看成一个 0 + xx的问题，每次遇到+/- 就计算出之前的结果，然后设置当前的sign， 用于下一次计算结果。
	
*/

class Solution {
public:
    int calculate(string s) {
        int res = 0, num = 0, sign = 1;
        stack<int> stk;
        for(int i=0; i<s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + (s[i] - '0');
            } else if (s[i] == ' ') {
                continue;
            } else if (s[i] == '+') {
                res += sign * num;
                num = 0;
                sign = 1;
            } else if (s[i] == '-') {
                res += sign * num;
                num = 0;
                sign = -1;
            } else if (s[i] == '(') {
                stk.push(res);
                stk.push(sign);
                res = 0;
                sign = 1;
                num = 0;
            } else if (s[i] == ')') {
                res += sign * num;
                res = stk.top() * res;
                stk.pop();
                res += stk.top();
                stk.pop();
                num = 0;
                sign = 1;
            }        
        }
        if (num != 0) res += sign * num;
        return res;
    }
};