/*

*/

//version 1(12 ms)
class Solution {
    public int maxCoins(int[] nums) {
        if (nums == null || nums.length == 0) return 0;
        int[][] dp = new int[nums.length][nums.length];
        for (int len=1; len<=nums.length; len++) {
            for (int i=0; i<=nums.length-len; i++) {
                int j = i + len - 1;
                for (int k=i; k<=j; k++) {
                    int left = 1, right = 1;
                    if (i != 0) left = nums[i-1];
                    if (j != nums.length-1) right = nums[j+1];
                    
                    int before = 0, after = 0;
                    if (k != i) before = dp[i][k-1];
                    if (k != j) after = dp[k+1][j];
                    
                    dp[i][j] = Math.max(dp[i][j], left * nums[k] * right + before + after);
                }
            }
        }
        return dp[0][nums.length-1];
    }
}