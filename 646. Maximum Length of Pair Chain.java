/*

*/

//version 1(161 ms)
class Solution {
    public int findLongestChain(int[][] pairs) {
        if (pairs.length == 0 || pairs[0].length == 0) return 0;
        int n = pairs.length, res = 0;
        int[] P =  new int[n];
        Arrays.fill(P, 1);
        Arrays.sort(pairs, (a,b) -> a[0] - b[0]);        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                P[i] = Math.max(P[i], pairs[i][0] > pairs[j][1] ? P[j] + 1 : P[j]);
            }
        }
        return P[n - 1];
    }
}

//version 2(53 ms)
class Solution {
    public int findLongestChain(int[][] pairs) {
        if (pairs.length == 0 || pairs[0].length == 0) return 0;
        int n = pairs.length, res = 0, i = 0, curEnd = 0;
        Arrays.sort(pairs, (a,b) -> a[1] - b[1]);
        while (i < n) {
            res++;
            curEnd = pairs[i][1];
            while (i < n && pairs[i][0] <= curEnd) i++;
        }
        return res;
    }
}