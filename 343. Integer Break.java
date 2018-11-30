/*
	方法一：
*/

//version 1()
class Solution {
    public int integerBreak(int n) {
        int[] dp = new int[n+1];
        dp[1] = 1;
        dp[0] = 0;
        for (int i=2; i<=n; i++) {
            dp[i] = 1;
            for (int j=1; j<i; j++) {
                dp[i] = Math.max(Math.max(dp[j], j) * Math.max(dp[i-j], i-j), dp[i]);
            }
        }
        return dp[n];
    }
}