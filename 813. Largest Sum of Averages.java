/*

*/

//version 1(11 ms)
class Solution {
    public double largestSumOfAverages(int[] A, int K) {
        double[][] D = new double[K+1][A.length + 1];        
        double total = 0.0;
        for (int k = 1; k <= K; k++) {
            for (int j = 1; j <= A.length; j++) {
                total += (double) A[j-1];
                if (k == 1) {
                    D[k][j] = total / j;
                    continue;
                }
                double sum = 0;
                for (int i = j; i > k - 1; i--) {
                    sum += (double) A[i-1];
                    D[k][j] = Math.max(D[k][j], D[k-1][i-1] + (double)sum / (j - i + 1));
                }                   
            }        
        }
        return D[K][A.length];
    }
}