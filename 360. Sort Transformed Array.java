/*

*/

//version 1(6 ms)
class Solution {
    public int[] sortTransformedArray(int[] nums, int a, int b, int c) {
        int[] res = new int[nums.length];
        int n = nums.length;
        int l = 0, r = nums.length - 1, i = a >= 0 ? n - 1 : 0;
        while (l <= r) {
            if (a >= 0) {
                res[i--] = quad(nums[l], a, b, c) >= quad(nums[r], a, b, c) ? quad(nums[l++], a, b, c) : quad(nums[r--], a, b, c);
            } else {
                res[i++] = quad(nums[l], a, b, c) <= quad(nums[r], a, b, c) ? quad(nums[l++], a, b, c) : quad(nums[r--], a, b, c);
            }
        }
        return res;
    }
    
    private int quad(int x, int a, int b, int c) {
        return a * x * x + b * x + c;
    }
    
    private void reverse(int[] A) {
        for (int i = 0; i < A.length / 2; i++) {
            int temp = A[i];
            A[i] = A[A.length - i - 1];
            A[A.length - i - 1] = temp;
        }
    }
}