/*

*/

//version 1(4 ms)
class Solution {
    
    private static int[] nx = {1, 2,  2,  1, -1, -2, -2, -1};
    private static int[] ny = {2, 1, -1, -2, -2, -1,  1,  2};
    private static final double step = 1.0 / 8.0; 
    
    public double knightProbability(int N, int K, int r, int c) {
        if (N == 0) return 0.0;
        if (K == 0) return 1.0;
        double[][] D = new double[N][N];
        D[r][c] = 1;
        for (int i = 0; i < K; i++) {
            double[][] next = new double[N][N];
            for (int x = 0; x < N; x++) {
                for (int y = 0; y < N; y++) {
                    if (D[x][y] != 0.0) {
                        //System.out.println(x + ", " + y);
                        nextMove(N, D, next, x, y);    
                    }
                }
            }
            
            if (i == 0) D[r][c] -= 1;
            D = next;
        }
        double res = 0.0;
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++) {
                res += D[x][y];
            }
        }
        return res;
    }
    
    private void nextMove(int N, double[][] D, double[][] next, int x, int y) {
        for (int i = 0; i < nx.length; i++) {
            int p = x + nx[i], q = y + ny[i];
            if (p >= 0 && q >= 0 && p < N && q < N) {
                next[p][q] += D[x][y] * step;
            }
        }
    }
}