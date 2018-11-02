/*
	方法一：分别实现flip和invert两个函数
	方法二：直接一个函数，通过XOR直接同时实现。
*/

//version 1()
class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        if (A == null || A.length == 0 || A[0].length == 0) return A;
        flip(A);
        invert(A);
        return A;
    }
    
    private void flip(int[][] A) {
        int len = A[0].length;
        for (int i=0; i<A.length; i++) {            
            for (int j=0; j<len/2; j++) {
                int temp = A[i][j];
                A[i][j] = A[i][len-j-1];
                A[i][len-j-1] = temp;
            }
        }
    }
    
    private void invert(int[][] A) {
        for (int i=0; i<A.length; i++) {
            for (int j=0; j<A[0].length; j++) {
                A[i][j] = 1 - A[i][j];
            }
        }
    }
}

//version 2(4 ms)
class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        if (A == null || A.length == 0 || A[0].length == 0) return A;
        int len = A[0].length;
        for (int i=0; i<A.length; i++) {
            for (int j=0; j<(len+1) /2; j++) {
                int temp = A[i][j] ^ 1;
                A[i][j] = A[i][len-j-1] ^ 1;
                A[i][len-j-1] = temp;
            }
        }
        return A;
    }
}