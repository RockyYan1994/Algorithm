/*
	first
	首先想到利用DP来解决这个问题，因为每一步都可以看作前一步和前两步可能性之和，查看discussion之后发现这个也可以理解为fibonacci函数
*/

//version 1(3 ms)
class Solution {
public:
    int climbStairs(int n) {
        if(n==0) return 0;
        vector<int> dp(n,0);
        dp[0] = 1,dp[1] = 2;
        for(int i=2;i<n;i++){
            dp[i] = dp[i-2] + dp[i-1];
        }
        return dp[n-1];
    }
};