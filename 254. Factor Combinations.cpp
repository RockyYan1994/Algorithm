/*
	方法一：
	方法二：
	方法三：从2开始，如果n%i == 0 说明满足条件，然后对n/i进行递归判断。
*/

//version 1(956 ms) 
class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        if (n == 1) return res;
        vector<int> arr;
        backtracking(res, arr, n, 1, 2);
        return res;
    }
    
    void backtracking(vector<vector<int>>& res, vector<int> arr, int n, int m, int num) {
        if (n < m) return;
        if (n == m) {
            res.push_back(arr);
            return;
        }
        for (int i=num; i<= n/2; i++) {
            int temp = m * i;
            if (n % temp) continue;
            if (temp > n) break;
            arr.push_back(i);
            backtracking(res, arr, n, temp, i);
            arr.pop_back();
        }
    }
};

//version 2(152 ms)
class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        if (n == 1) return res;
        vector<int> arr;
        backtracking(res, arr, n, 2);
        return res;
    }
    
    void backtracking(vector<vector<int>>& res, vector<int> arr, int n, int idx) {
        if (n <= 1 && arr.size() > 1) {
            res.push_back(arr);
            return;
        }
        for (int i=idx; i<= n; i++) {
            if (n % i == 0) {
                arr.push_back(i);
                backtracking(res, arr, n/i, i);
                arr.pop_back();
            }
        }
    }
};


//version 3 (0 ms)
class Solution {
public:
    
    void getFactors(int n, vector<int>& curr, vector<vector<int>>& facs) {
        int prev = (curr.size() > 0) ? curr.back() : 2;
        for (int i = prev; i <= int(sqrt(n)); i++) {
            if (n % i != 0) {
                continue;
            }
            curr.push_back(i);
            curr.push_back(n / i);
            facs.push_back(curr);
            curr.pop_back();
            getFactors(n / i, curr, facs);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> facs;
        vector<int> curr;
        getFactors(n, curr, facs);
        return facs;
    }
};