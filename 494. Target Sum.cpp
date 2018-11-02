/*
	方法一：暴力解，直接采用递归把每种可能性都尝试一下。
	方法二：采用 https://leetcode.com/problems/target-sum/discuss/97334/Java-(15-ms)-C++-(3-ms)-O(ns)-iterative-DP-solution-using-subset-sum-with-explanation
		的方法，把根据公式，推导并转化成nums到具体target的方法一共有多少种。同时可以进行空间优化。
*/

//version 1(432 ms)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        return helper(nums, S, 0, 0);
    }
    int helper(vector<int>& nums, int S, int n, int i) {
        if (i == nums.size()) {
            if (n == S) return 1;
            else return 0;
        }
        return helper(nums, S, n+nums[i], i+1) + helper(nums, S, n-nums[i], i+1);
    }
};

//version 2(4 ms)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (auto num : nums) {
            sum += num;
        }        
        return (S + sum) % 2 == 0 && sum >= S ? helper(nums, (S + sum)/2) : 0;
    }
    int helper(vector<int>& nums, int sum) {
        vector<int> dp(sum+1, 0);
        dp[0] = 1;
        for (auto num : nums) {
            for (int i=sum; i>=num; i--) {
                dp[i] += dp[i-num];
            }
        }
        return dp[sum];
    }
};

class Solution {
    public int findTargetSumWays(int[] nums, int S) {
        int totalSum = 0;
        for (int num : nums) {  //calculate the totalSum keeping all the elements in the array positive
            totalSum += num;  
        }
        if (totalSum < S || -totalSum > S) { //If the target sum S is not reachable by the range
            return 0;
        }
        int[] dp = new int[2 * totalSum + 1];
         //dp[i] -> the number of ways to have sum = i - totalSum
        dp[totalSum] = 1; 
        //We start from no elements in the array, so there is one way to have sum = 0 that there is no element
        for (int i = 0; i < nums.length; i++) { //Start from deciding to add the first element as positive or negative
            int[] next = new int[2 * totalSum + 1];
            for (int j = 0; j < 2 * totalSum + 1; j++) {
                if (dp[j] != 0) {  //if current sum j - totalSum is already reached by the previous searched numbers
                    next[j + nums[i]] += dp[j]; //plus the num of ways to have sum = j - totalSum to the num of ways to have sum = j + nums[i] - totalSum 
                    next[j - nums[i]] += dp[j];
                }//The previous reached range is  -totalSum < [-currSum, currSum ] < totalSum.
                //Since currSum + nums[i] no larger than totalSum, -currSum - nums[i] no smaller than -totalSum, so it won't exceed the boundary
            }
            dp = next;
        }
        return dp[S + totalSum]; //return the num of ways to have sum = S
    }
};