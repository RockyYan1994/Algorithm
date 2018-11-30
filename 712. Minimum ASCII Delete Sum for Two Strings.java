/*
	方法一：采用DP，需要注意初始化条件应该是不断累加，并且D[0][0] = 0., 
*/

//version 1(24 ms)
class Solution {
    public int minimumDeleteSum(String s1, String s2) {
        int m = s1.length(),  n = s2.length();
        int[][] D = new int[s1.length()+1][s2.length()+1];
        for (int i=1; i<=m; i++) {
            D[i][0] = D[i-1][0] + (int)s1.charAt(i-1);
        }
        for (int j = 1; j<= n; j++) {
            D[0][j] = D[0][j-1] + (int)s2.charAt(j-1);
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j<=n; j++) {                
                D[i][j] = Math.min(D[i-1][j] + s1.charAt(i-1), D[i][j-1] + s2.charAt(j-1));
                if (s1.charAt(i-1) == s2.charAt(j-1)) {
                    D[i][j] = Math.min(D[i-1][j-1], D[i][j]);
                }
            }
        }
        return D[m][n];
    }
}