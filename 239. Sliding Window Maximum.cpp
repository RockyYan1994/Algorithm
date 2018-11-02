/*
	方法一：采用最简单的方法，每次都遍历窗口找最小值。
*/

//version 1(32 ms) JAVA
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (nums.length == 0) return new int[0];
        int[] res = new int[nums.length - k + 1];
        for (int i=0; i<nums.length-k+1; i++) {
            int l = i, r = i+k;
            res[i] = findMax(nums, l, r);
        }
        return res;
    }
    
    public static int findMax(int[] nums, int l, int r) {
        int res = nums[l];
        for (int i=l+1;i<r;i++) res = Math.max(res, nums[i]);
        return res;
    }
}

//version 2(44 ms) C++
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int> q;
        vector<int> res;
        for (int i=0;i<n;i++) {
            if(!q.empty() && q.front()<i-k+1) q.pop_front();
            while (!q.empty() && nums[q.back()] < nums[i]) q.pop_back();
            q.push_back(i);
            if(i>=k-1) res.push_back(nums[q.front()]);
        }
        return res;
    }
};