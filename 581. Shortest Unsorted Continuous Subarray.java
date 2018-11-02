/*
	方法一：采用一个l和r来记录，同时记录之前的max值。
*/


//version 1(37 ms)
class Solution {
    public int findUnsortedSubarray(int[] nums) {
        if (nums.length == 0) return 0;
        int l = -1, r = 0, max = nums[0];
        for (int i=1; i<nums.length; i++) {
            if (nums[i] < nums[i-1] || nums[i] < max) {
                l = l == -1 ? findFirstIndex(nums, nums[i]) : Math.min(findFirstIndex(nums, nums[i]), l);
                r = i;                
            }
            max = Math.max(max, nums[i]);
        }
        return l == -1 ? 0 : r-l+1;
    }
    
    private int findFirstIndex(int[] nums, int val) {
        for (int i=0; i<nums.length; i++) {
            if (nums[i] > val) {
                return i;
            }
        }
        return -1;
    }
}