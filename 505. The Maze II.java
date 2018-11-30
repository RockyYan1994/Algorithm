/*

*/

//version 1(444 ms)
class Solution {
    
    private static int[][] dirs = new int[][]{{1,0}, {0,1}, {0, -1}, {-1, 0}};
    
    public int shortestDistance(int[][] maze, int[] start, int[] destination) {
        int[][] D = new int[maze.length][maze[0].length];
        for (int i = 0; i < maze.length; i++) {
            Arrays.fill(D[i], Integer.MAX_VALUE);
        }
        D[start[0]][start[1]] = 0;
        dfs(maze, D, start, destination);
        return D[destination[0]][destination[1]] == Integer.MAX_VALUE ? -1 : D[destination[0]][destination[1]];
    }
    
    private void dfs(int[][] maze, int[][] D, int[] start, int[] destination) {
        for (int i = 0; i < dirs.length; i++) {
            int x = start[0], y = start[1], cnt = 0;
            while (x >= 0 && y >= 0 && x < maze.length && y < maze[0].length && maze[x][y] == 0) {
                x = x + dirs[i][0]; y = y + dirs[i][1];
                cnt++;
            }
            if (cnt > 0 && cnt - 1 + D[start[0]][start[1]] < D[x - dirs[i][0]][y - dirs[i][1]]) {
                D[x - dirs[i][0]][y - dirs[i][1]] = cnt - 1 + D[start[0]][start[1]];
                dfs(maze, D, new int[]{x - dirs[i][0], y - dirs[i][1]}, destination);
            }
        }
    }
}