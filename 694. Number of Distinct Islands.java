/*
*/

//version 1(29 ms)
class Solution {
    
    private int[][] dirs = new int[][] {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    public int numDistinctIslands(int[][] grid) {
        int m = grid.length, n = grid[0].length, res = 0;
        boolean[][] flags = new boolean[m][n];
        Set<String> set = new HashSet<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !flags[i][j]) {
                    StringBuilder sb = new StringBuilder();
                    dfs(grid, flags, i, j, sb);                    
                    String path = sb.toString();
                    //System.out.println(path);
                    if (!set.contains(path)) {                        
                        res++;                        
                    }
                    set.add(path);
                }
            }
        }
        return res;
    }
    
    private void dfs(int[][] grid, boolean[][] flags, int x, int y, StringBuilder sb) {        
        for (int i = 0; i < dirs.length; i++) {
            int p = x + dirs[i][0], q = y + dirs[i][1];
            if (p >= 0 && q >= 0 && p < grid.length && q < grid[0].length && grid[p][q] == 1 && !flags[p][q]) {
                flags[p][q] = true;
                sb.append(" " + dirs[i][0] + "," + dirs[i][1]);
                dfs(grid, flags, p, q, sb);
            }
        }
        sb.append("-");
    }
}

//version 2()
class Solution {
    
    private int[][] dirs = new int[][] {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    public int numDistinctIslands(int[][] grid) {
        int m = grid.length, n = grid[0].length, res = 0;        
        Set<String> set = new HashSet<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    StringBuilder sb = new StringBuilder();
                    dfs(grid, i, j, sb);
                    String path = sb.toString();
                    //System.out.println(path);
                    set.add(path);
                }
            }
        }
        return set.size();
    }
    
    private void dfs(int[][] grid, int x, int y, StringBuilder sb) {        
        for (int i = 0; i < dirs.length; i++) {
            int p = x + dirs[i][0], q = y + dirs[i][1];
            if (p >= 0 && q >= 0 && p < grid.length && q < grid[0].length && grid[p][q] == 1) {
                grid[p][q] = 0;
                sb.append(i);
                dfs(grid, p, q, sb);
            }
        }
        sb.append('-');
    }
}