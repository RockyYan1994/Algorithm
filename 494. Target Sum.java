/*
	方法三：采用DP，通过创建2*sum+1，记录每一个sum的能够到达的数量。
*/

//version 1()
class Solution {
    public int findTargetSumWays(int[] nums, int S) {
        int n = nums.length;
        int sum = 0;
        for (int num : nums) sum += num;
        if (S > sum) return 0;
        
        int[][] dp = new int[n+1][2*sum + 1];
        dp[0][sum] = 1;
        for (int i=1; i<=n; i++) {
            for (int j=0; j<2*sum+1; j++) {
                int minus = (j-nums[i-1] >= 0 && j-nums[i-1] < 2*sum+1) ? dp[i-1][j-nums[i-1]] : 0;
                int add = (j+nums[i-1] >=0 && j+nums[i-1] < 2*sum+1) ? dp[i-1][j+nums[i-1]] : 0;
                dp[i][j] = minus + add;
            }
        }
        return dp[n][S+sum];
    }
}	
