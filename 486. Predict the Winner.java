/*

*/

//version 1(3 ms)
class Solution {
    public boolean PredictTheWinner(int[] nums) {
        int n = nums.length;
        int[][] D = new int[n][n];
        for (int len = 0; len < n; len++) {
            for (int i = 0; i + len < n; i++) {
                int j = i + len;
                D[i][j] = len == 0 ? nums[i] : Math.max(nums[i] - D[i+1][j], nums[j] - D[i][j-1]);
            }
        }
        
        return D[0][n-1] >= 0;
    }
}

//version 2(3 ms)
class Solution {
    public boolean PredictTheWinner(int[] nums) {
        int n = nums.length;
        int[] D = new int[n];
        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j) {
                    D[i] = nums[i];
                    continue;
                }
                D[j] = Math.max(nums[i] - D[j], nums[j] - D[j-1]);
            }
        }
        return D[n-1] >= 0;
    }
}

//version 2(2 ms)
class Solution {
    public boolean PredictTheWinner(int[] nums) {
        int n = nums.length;
        if ((n & 1) == 0) return true;
        int[] D = new int[n];
        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j) {
                    D[i] = nums[i];
                    continue;
                }
                D[j] = Math.max(nums[i] - D[j], nums[j] - D[j-1]);
            }
        }
        return D[n-1] >= 0;
    }
}