/*

*/

//version 1 (36 ms)
class Solution {
    public int longestPalindromeSubseq(String s) {
        int n = s.length();        
        int[][] D = new int[n][n];
        for (int i = 0; i<n; i++) {            
            D[i][i] = 1;
        }
        for (int i = 1; i < n; i++) {
            for (int j = i-1; j >= 0; j--) {
                D[i][j] = Math.max(D[i-1][j], D[i][j+1]);
                if (s.charAt(i) == s.charAt(j)) {
                    D[i][j] = Math.max(D[i-1][j+1] + 2, D[i][j]);
                }
            }
        }
        return D[n-1][0];
    }
}

//version 2(71 ms)
class Solution {
    public int longestPalindromeSubseq(String s) {
        int n = s.length();              
        return helper(0, n-1, new int[n][n], s);
    }
    
    private int helper(int i, int j, int[][] D, String s) {
        if (i > j || i >= D.length || j < 0) return 0;
        if (i == j) D[i][j] = 1;
        if (D[i][j] != 0) return D[i][j];
        D[i][j] = Math.max(helper(i+1, j, D, s), helper(i, j-1, D, s));
        if (s.charAt(i) == s.charAt(j)) {
            D[i][j] = Math.max(helper(i+1, j-1, D, s) + 2, D[i][j]);  
        }
        return D[i][j];
    }
}

//version 3(22 ms)
class Solution {
    public int longestPalindromeSubseq(String s) {
        int n = s.length();              
        return helper(0, n-1, new int[n][n], s);
    }
    
    private int helper(int i, int j, int[][] D, String s) {        
        if (i > j || i >= D.length || j < 0) return 0;        
        if (i == j) D[i][j] = 1;
        if (D[i][j] != 0) return D[i][j];
        
        if (s.charAt(i) == s.charAt(j)) {
            D[i][j] = Math.max(helper(i+1, j-1, D, s) + 2, D[i][j]);  
        } else {
            D[i][j] = Math.max(helper(i+1, j, D, s), helper(i, j-1, D, s));
        }
        return D[i][j];
    }
}