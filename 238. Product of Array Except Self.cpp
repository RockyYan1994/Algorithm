/*
	方法一：主要通过分别计算当前元素左边和右边的结果，然后相乘。
	方法二：通过一个变量计算右边结果， 减少空间复杂度。
*/

//version 1(1 ms)
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] left = new int[nums.length];
        int[] right = new int[nums.length];
        left[0] = nums[0];
        right[nums.length-1] = nums[nums.length-1];
        for (int i=1; i< nums.length; i++) left[i] = left[i-1] * nums[i];
        for (int i=nums.length-2; i>=0; i--) right[i] = right[i+1] * nums[i];
        for (int i=0; i<nums.length;i++) {
            int l = (i != 0) ? left[i-1] : 1;
            int r = (i != nums.length-1) ? right[i+1] : 1;
            nums[i] = l * r;
        }
        return nums;
    }
}

class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] res = new int[n];
        res[0] = 1;
        for (int i=1;i<n;i++) res[i] = res[i-1] * nums[i-1]; 
        int right = nums[n-1];
        for (int i=n-2;i>=0;i++) res[i] *= 
        return nums;
    }
}