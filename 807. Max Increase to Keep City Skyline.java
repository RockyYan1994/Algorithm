/*

*/

//version 1(6 ms)
class Solution {
    public int maxIncreaseKeepingSkyline(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[] x = new int[m];
        int[] y = new int[n];        
        for (int i = 0; i < m; i++) {
            x[i] = 0;
            for (int j = 0; j < n; j++) {
                x[i] = Math.max(grid[i][j], x[i]);
            }
        }
        for (int i = 0; i < n; i++) {
            y[i] = 0;
            for (int j = 0; j < m; j++) {
                y[i] = Math.max(grid[j][i], y[i]);
            }
        }
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res += Math.min(x[i], y[j]) - grid[i][j];
            }
        }
        return res;
    }
}