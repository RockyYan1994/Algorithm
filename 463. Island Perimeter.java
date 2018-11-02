/*

*/

//version 1(64 ms)
class Solution {
    public int islandPerimeter(int[][] grid) {
        if (grid.length == 0 || grid[0].length == 0) return 0;
        int islands = 0, neighbors = 0;
        for (int i=0; i<grid.length; i++) {
            for (int j=0; j<grid[0].length; j++) {
                if (grid[i][j] == 1) {
                    islands++;
                    if (i+1<grid.length && grid[i+1][j] == 1) neighbors++;
                    if (j+1<grid[0].length && grid[i][j+1] == 1) neighbors++;
                }
            }
        }
        return islands*4 - neighbors*2;
    }
}