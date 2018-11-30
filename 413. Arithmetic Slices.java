/*

*/

//version 1(112 ms)
class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        int res = 0;
        if (A.length == 0) {
            return res;
        }
        boolean[][] D = new boolean[A.length][A.length];
        for (int k = 2; k < A.length; k++) {
            for (int i = 0; i < A.length - k; i++) {
                if (k == 2) {
                    if ((A[i] - A[i+1] == A[i+1] - A[i+2])) {
                        D[i][i+k] = true;
                        res++;
                    } else {
                        D[i][i+k] = false;   
                    }                    
                } else {
                    if (D[i][i+k-1] && D[i+1][i+k]) {
                        res++;
                        D[i][i+k] = true;
                    } else {
                        D[i][i+k] = false;
                    }
                }
            }
        }
        return res;
    }
}

//version 2(1 ms)
class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        int res = 0, temp = 0;        
        for (int i = 2; i<A.length; i++) {
            if (A[i - 2] - A[i - 1] == A[i - 1] - A[i]) {
                temp++;
                res += temp;
            } else {
                temp = 0;
            }
        }
        return res;
    }
}