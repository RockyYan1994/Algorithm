/*

*/

//version 1()
class Solution {
    public int minCostClimbingStairs(int[] cost) {
        if (cost.length < 2) return 0;
        int[] D = new int[cost.length];
        D[0] = cost[0];
        D[1] = cost[1];
        for (int i = 2; i < cost.length; i++) {
            D[i] = Math.min(D[i-1], D[i-2]) + cost[i];
        }
        return Math.min(D[cost.length-1], D[cost.length-2]);
    }
}