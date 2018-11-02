/*
    方法一：DP，时间复杂度O(n^2)
    方法二：DP，时间复杂度O(nlogn)
*/

//version 1(28 ms)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> dp(nums.size(), 1);
        for (int i=0; i<nums.size(); i++) {
            for (int j=0; j<=i; j++) {
                if (nums[i] > nums[j] && dp[i] < dp[j]+1) dp[i] = dp[j]+1;
            }
        }
        int res = 0;
        for (int i=0; i<nums.size(); i++) {
            res = max(res, dp[i]);
        }
        return res;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> dp(nums.size(), 0);
        int len = 0;
        for (auto num : nums) {
            if (num <= dp[0]) {
                dp[0] = num;
            } else if (num > dp[len-1]) {
                dp[len] = num;
            } else {
                auto it = upper_bound(dp.begin(), dp.begin() + len, num);
                *it = num;
            }
        }
        return len;
    }
}
