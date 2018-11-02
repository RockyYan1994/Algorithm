/*
	采用对每个运算符的左边和右边进行递归运算，然后将所有可能结果进行组合。
*/

//version 1(0 ms)
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        int n = input.size();
        int num = 0;
        for (int i=0; i<n; i++) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                string ls = input.substr(0, i);
                string rs = input.substr(i+1, n-i);
                vector<int> left = diffWaysToCompute(ls);
                vector<int> right = diffWaysToCompute(rs);
                for (int k = 0;k<left.size();k++) {
                    for (int j = 0;j<right.size();j++) {
                        if (input[i] == '+') res.push_back(left[k] + right[j]);
                        else if (input[i] == '-') res.push_back(left[k] - right[j]);
                        else res.push_back(left[k] * right[j]);
                    }
                }
            }
        }
        if (res.empty()) {
            // cout << input << endl;
            res.push_back(stoi(input));            
        }
        return res;
    }
};