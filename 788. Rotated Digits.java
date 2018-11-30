/*

*/

//version 1(4 ms)
class Solution {
    public int rotatedDigits(int N) {
        int res = 0;
        int[] D = new int[N+1];
        for (int i = 0; i <= N; i++) {
            if (i < 10) {
                if (i == 0 || i == 1 || i == 8) {
                    D[i] = 1;
                } else if (i == 2 || i == 5 || i == 6 || i == 9) {
                    D[i] = 2;
                    res++;
                }
            } else {
                int a = D[i/10], b = D[i%10];
                if (a == 1 && b == 1) {
                    D[i] = 1;
                } else if (a >= 1 && b >= 1) {
                    D[i] = 2;
                    res++;
                }
            }
        }
        return res;
    }
}