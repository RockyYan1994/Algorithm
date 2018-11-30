/*

*/

//version 1()
class Solution {
    
    private int[] nx = {0, 1, 0, -1};
    
    private int[] ny = {1, 0, -1, 0};
    
    public int longestIncreasingPath(int[][] matrix) {       
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) return 0;
        int m = matrix.length, n = matrix[0].length, res = 0;        
        int[][] D = new int[m][n];
        boolean[][] flag = new boolean[m][n];
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                D[i][j] = dfs(D, flag, matrix, i, j);
                res = Math.max(D[i][j], res);
            }
        }
        return res;
    }
    
    private int dfs(int[][] D, boolean[][] flag, int[][] matrix, int i, int j) {
        if (flag[i][j] == true) {
            return D[i][j];
        }
        
        int ans = 1;
        for (int k = 0; k < nx.length; k++) {
            int x = i + nx[k], y = j + ny[k];
            if (x >=0 && y >= 0 && x < matrix.length && y < matrix[0].length && matrix[i][j] > matrix[x][y]) {
                ans = Math.max(ans, dfs(D, flag, matrix, x, y) + 1);
            }
        }
        
        flag[i][j] = true;
        D[i][j] = ans;
        return ans;
    }
}