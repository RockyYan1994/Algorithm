/*
	方法一：采用recursion，关键点在于当val == target的时候，如果没有到达k分组，就执行helper(nums, visited, n, 0, k-1, target, 0);并且必须要在循环外
	执行。
*/

//version 1(7 ms)
class Solution {
    public boolean canPartitionKSubsets(int[] nums, int k) {
        int sum = 0, n = nums.length;
        if (n == 0 || k == 0) return false;
        for (int num : nums) {
            sum += num;
        }
        if (sum % k != 0) return false;
        int target = sum / k;
        
        return helper(nums, new int[n], n, 0, k, target, 0);
    }
    
    private boolean helper(int[] nums,int[] visited, int n, int index, int k, int target, int val) {
        if (k == 1 && val == target) return true;
        if (index >= n) return false;
        if (val == target) return helper(nums, visited, n, 0, k-1, target, 0);
        for (int i=index; i<n; i++) {
            if (visited[i] != 0 || val + nums[i] > target) continue;            
            visited[i] = 1;              
            if (helper(nums, visited, n, i+1, k, target, val + nums[i])) return true;
            visited[i] = 0;
        }
        return false;
    }
}