/*

*/

//version 1(5 ms)
class Solution {
    public int findCircleNum(int[][] M) {
        int res = M.length, n = M.length;
        int[] circles = new int[M.length];
        for (int i = 0; i < n; i++) {
            circles[i] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (M[i][j] != 1) {
                    continue;
                }
                int a = find(circles, i), b = find(circles, j);
                if (a != b) {
                    circles[b] = a;
                    res--;
                }
            }
        }
        return res;
    }
    
    private int find(int[] circles, int person) {
        if (circles[person] != person) {
            circles[person] = find(circles, circles[person]);
        }
        return circles[person];
    }
}