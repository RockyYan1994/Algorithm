/**
	方法一：BFS实现。
    方法二：采用DP实现，时间为O(amount * n) 空间为O(amount)；
*/

//version 1(111 ms)
class Solution {
    public int coinChange(int[] coins, int amount) {
        if (coins.length == 0) return -1;
        if (amount == 0) return 0;
        Set<Integer> visited = new HashSet<Integer>();
        Queue<Integer> sums = new LinkedList<Integer>();
        int layer = 0;
        for (int coin : coins) {
            if (coin == amount) return 1;
            sums.add(coin);
        }
        
        while (!sums.isEmpty()) {
            layer++;
            int len = sums.size();
            for (int i=0; i<len; i++) {
                int cur = sums.poll();
                for (int j=0; j<coins.length; j++) {
                    int temp = cur + coins[j];
                    if (temp == amount) {
                        return layer+1;
                    } else if (temp > amount || visited.contains(temp)) {
                        continue;
                    } else {
                        sums.add(temp);
                    }
                    visited.add(temp);
                }
            }
        }        
        return -1;
    }
}

//version 2(24 ms)
class Solution {
    public int coinChange(int[] coins, int amount) {
        if (amount == 0) return 0;
        int max = amount + 1;
        int[] dp = new int[amount+1];
        Arrays.fill(dp, max);
        dp[0] = 0;
        for (int i=1; i<=amount; i++) {
            for (int j=0; j<coins.length; j++) {
                if (i >= coins[j]) {
                    dp[i] = Math.min(dp[i-coins[j]]+1, dp[i]);   
                }
            }
        }
        return dp[amount] >= max ? -1 : dp[amount];
    }
}