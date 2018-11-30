/*
	方法一：采用DP，是01knapkin的问题，一开始想成了另一个DP问题，重复计算了值。
*/	

//version 1()
class Solution {
    public int change(int amount, int[] coins) {
        int n = coins.length;
        int[][] A = new int[n+1][amount+1];
        for (int i = 0; i <= n; i++) {
            A[i][0] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= amount; k++) {
                A[i][k] = A[i-1][k];
                if (k >= coins[i-1]) {
                    A[i][k] += A[i][k-coins[i-1]];
                }
            }
        }
        return A[n][amount];
    }
}