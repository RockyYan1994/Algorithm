/*

*/

//version 1(441 ms)
class Solution {
    
    private int[][] dirs = new int[][] {{1,0}, {0,1}, {-1,0}, {0,-1}};
    private int m,n;
    
    public List<int[]> pacificAtlantic(int[][] matrix) {
        if (matrix.length == 0 || matrix[0].length == 0) return new ArrayList<int[]>();
        m = matrix.length; n = matrix[0].length;
        List<int[]> res = new ArrayList();
        int[][] pacific = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific(matrix, new boolean[m][n], i, j) 
                    && atlantic(matrix, new boolean[m][n], i, j)) {
                    res.add(new int[] {i, j});   
                }                    
            }
        }
        return res;
    }
    
    private boolean pacific(int[][] matrix, boolean[][] visited, int x, int y) {
        if (visited[x][y]) return false;
        if (x == 0 || y == 0) return true;
        visited[x][y] = true;
        for (int i = 0; i < dirs.length; i++) {
            int p = x + dirs[i][0], q = y + dirs[i][1];
            if (p >= 0 && q >= 0 && p < m && q < n && matrix[x][y] >= matrix[p][q]) {
                if (pacific(matrix, visited, p, q)) return true;
            }
        }
        return false;
    }
    
    private boolean atlantic(int[][] matrix, boolean[][] visited, int x, int y) {
        if (visited[x][y]) return false;
        if (x == m-1 || y == n-1) return true;
        visited[x][y] = true;
        for (int i = 0; i < dirs.length; i++) {
            int p = x + dirs[i][0], q = y + dirs[i][1];
            if (p >= 0 && q >= 0 && p < m && q < n && matrix[x][y] >= matrix[p][q]) {
                if (atlantic(matrix, visited, p, q)) return true;
            }
        }
        return false;
    }
}

//version 2(13 ms)
class Solution {
    
    private int[][] dirs = new int[][] {{1,0}, {0,1}, {-1,0}, {0,-1}};
    private int m,n;
    
    public List<int[]> pacificAtlantic(int[][] matrix) {
        if (matrix.length == 0 || matrix[0].length == 0) return new ArrayList<int[]>();
        m = matrix.length; n = matrix[0].length;
        List<int[]> res = new ArrayList();
        boolean[][] pacific = new boolean[m][n];
        boolean[][] atlantic = new boolean[m][n];
        Queue<int[]> P = new LinkedList<>(), Q = new LinkedList<>();
        for (int i = 0; i < m; i++) {
            P.add(new int[]{i, 0});
            Q.add(new int[]{i, n-1});
            pacific[i][0] = true;
            atlantic[i][n-1] = true;
        }
        for (int i = 0; i < n; i++) {
            P.add(new int[]{0, i});
            Q.add(new int[]{m-1, i});
            pacific[0][i] = true;
            atlantic[m-1][i] = true;
        }
        
        bfs(matrix, pacific, P);
        bfs(matrix, atlantic, Q);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    res.add(new int[] {i, j});
                }
            }
        }
        return res;
    }
    
    private void bfs(int[][] matrix, boolean[][] visited, Queue<int[]> queue) {        
        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int x = cur[0], y = cur[1];             
            for (int i = 0; i < dirs.length; i++) {
                int p = x + dirs[i][0], q = y + dirs[i][1];
                if (p >= 0 && q >= 0 && p < m && q < n && !visited[p][q] && matrix[x][y] <= matrix[p][q]) {
                    visited[p][q] = true;
                    queue.add(new int[]{p,q});
                }
            }
        }        
    }
}