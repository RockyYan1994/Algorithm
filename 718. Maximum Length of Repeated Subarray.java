/*
*/

//version 1()
class Solution {
    public int findLength(int[] A, int[] B) {
        int[][] D = new int[A.length+1][B.length + 1];
        int max = 0;
        for (int i = 1; i <= A.length; i++) {
            for (int j = 1; j <= B.length; j++) {                
                if (A[i-1] == B[j-1]) {
                    D[i][j] = Math.max(D[i-1][j-1] + 1, D[i][j]);
                } else {
                    D[i][j] = 0;
                }
                max = Math.max(max, D[i][j]);
            }
        }
        return max;
    }
}