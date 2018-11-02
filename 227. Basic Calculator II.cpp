/*

*/

class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        char opr = '+';
        int num = 0;
        for(int i=0;i<s.size();i++) {
            if(isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }
            if(!isdigit(s[i]) && (s[i] != ' ') || i == s.size()-1) {
                if(opr == '+') nums.push(num);
                else if (opr == '-') nums.push(-num);
                else if (opr == '*') {
                    int last = nums.top();
                    nums.pop();
                    nums.push(last * num);
                } else if (opr == '/') {
                    int last = nums.top();
                    nums.pop();
                    nums.push(last / num);
                }
                opr = s[i];
                num = 0;
            }
        }
        int res = 0;
        while (!nums.empty()) {
            res += nums.top();
            nums.pop();
        }
        return res;
    }
};