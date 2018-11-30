/*

*/

//version 1(6 ms)
class Solution {
    public int[] sortArrayByParityII(int[] A) {
        if (A.length == 0) return new int[]{};
        int even = 0, odd = 1;
        while (even < A.length && odd < A.length) {
            while (even < A.length && A[even] % 2 == 0) {
                even += 2;
            }
            while (odd < A.length && A[odd] % 2 == 1) {
                odd += 2;                
            }
            if (even >= A.length || odd >= A.length) break;
            int temp = A[even];
            A[even] = A[odd];
            A[odd] = temp;
        }
        return A;
    }
}