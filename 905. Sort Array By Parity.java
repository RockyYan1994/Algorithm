/*

*/

//version 1()
class Solution {
    public int[] sortArrayByParity(int[] A) {
        int l = 0, r = A.length - 1;
        while (l < r) {
            while (l < r && A[l] % 2 == 0) {
                l++;
            }
            while (l < r && A[r] % 2 == 1) {
                r--;
            }
            int temp = A[l];
            A[l] = A[r];
            A[r] = temp;
        }
        return A;
    }
}