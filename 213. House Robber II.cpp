/*
	1, 第一个方法主要是分别去掉头和尾部，然后取最大值。
	2, 优化是可以采用O(1)的空间大小来实现。
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        if(n == 3) return max(nums[0], max(nums[1], nums[2]));
        return max(robHelper(nums, 0, nums.size()-1), robHelper(nums, 1, nums.size()));
    }
    int robHelper(vector<int>& nums, int start, int end) {
        int n = end - start;
        vector<int> dp(n, 0);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start+1]);
        for(int i=2; i<n; i++){
            dp[i] = max(dp[i-1], dp[i-2]+nums[i+start]);
        }
        return dp[n-1];
    }
};