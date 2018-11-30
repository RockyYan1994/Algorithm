/*

*/

//version 1(6 ms)
class Solution {
    public boolean hasPath(int[][] maze, int[] start, int[] destination) {
        boolean[][] arrive = new boolean[maze.length][maze[0].length];
        arrive[start[0]][start[1]] = true;
        return dfs(maze, arrive, start, destination);
    }
    
    private boolean dfs(int[][] maze, boolean[][] arrive, int[] start, int[] destination) { 
        for (int i = 0; i < dirs.length; i++) {
            int x = start[0], y = start[1];
            while (x >= 0 && y >= 0 && x < maze.length && y < maze[0].length && maze[x][y] == 0) {
                x += dirs[i][0];
                y += dirs[i][1];                
            }
            //System.out.println("x:" + x + ", y:" + y);
            x -= dirs[i][0];
            y -= dirs[i][1];
            if ( arrive[x][y] == true) continue;
            arrive[x][y] = true;            
            if (x == destination[0] && y == destination[1]) return true;
            if(dfs(maze, arrive, new int[]{x, y}, destination)) return true;            
        }        
        return false;
    }
    
    private int[][] dirs = new int[][] {{1,0}, {0,1}, {0, -1}, {-1, 0}};
}