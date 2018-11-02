/*
	方法一：根据不同情况，修改string中每两个位置中的值。
	方法二：查看答案，从中间往两边加。
*/

//version 1(32 ms)
class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> res;
        if (n == 0) return res;
        string s(n, '.');
        backtracking(res, n/2, s);
        return res;
    }
    void backtracking(vector<string>& res, int idx, string s) {
        if (idx == s.size()) {
            res.push_back(s);
            return;
        }
        int n = s.size();        
        vector<string> nums = {"00", "11", "88", "69", "96"};
        int l = 0, r = nums.size();
        if (n % 2 == 1 && idx == n / 2) r = nums.size() - 2;
        if (idx == n-1 && idx != 0) l = 1;
        for (int i=l;i<r;i++) {
            s[idx] = nums[i][0];
            s[n-1-idx] = nums[i][1];
            backtracking(res, idx + 1, s);
        }
    }
};

//version 2(16 ms)
class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return helper(n, n);
    }
    vector<string> helper(int n, int m) {
        vector<string> res;
        if (n == 0) return {""};
        if (n == 1) return {"0", "1", "8"};
        
        vector<string> child = helper(n-2, m);
        
        for (int i=0; i<child.size(); i++) {
            if (n != m) res.push_back("0" + child[i] + "0");
            res.push_back("1" + child[i] + "1");
            res.push_back("8" + child[i] + "8");
            res.push_back("9" + child[i] + "6");
            res.push_back("6" + child[i] + "9");
        }
        
        return res;
    }
};