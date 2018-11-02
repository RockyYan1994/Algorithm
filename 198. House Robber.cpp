/*
	方法一：用DP实现。
	方法二：采用两个变量简化
*/

//version 1(0 ms)
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        int dp[n+1][2];
        memset(dp, 0, sizeof dp);
        for (int i=1; i<=n; i++) {
            dp[i][0] = max(dp[i-1][1], dp[i-1][0]);
            dp[i][1] = dp[i-1][0] + nums[i-1];
        }
        return max(dp[n][0], dp[n][1]);
    }
};

//version 2()
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        int a = 0, b = 0;
        for (int i=0; i<n; i++) {
            int temp = a;
            a = max(a, b);
            b = temp + nums[i];
        }
        return max(a, b);
    }
O