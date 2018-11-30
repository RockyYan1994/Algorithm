/*

*/

//version 1(19 ms)
class Solution {
    
    private int[] nx = {0, 1, 0, -1};
    private int[] ny = {1, 0, -1, 0};
    
    public int maxAreaOfIsland(int[][] grid) {
        if (grid.length == 0 || grid[0].length == 0) return 0;
        int res = 0;
        boolean[][] flags = new boolean[grid.length][grid[0].length];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 1) {
                    res = Math.max(res, dfs(flags, grid, i, j));
                }
            }
        }
        return res;
    }
    
    private int dfs(boolean[][] flags, int[][] grid, int x, int y) {
        if (flags[x][y] == true) {
            return 0;
        }
        int res = 1;
        flags[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int p = x + nx[i], q = y + ny[i];
            if (p >= 0 && q >= 0 && p < grid.length && q < grid[0].length && grid[p][q] == 1) {
                res += dfs(flags, grid, p, q);
            }
        }
        return res;
    }
}