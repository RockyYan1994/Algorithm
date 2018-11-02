/*
	首先想到顺序，但是要求的时间复杂度为logn，因此采用二分查找法。
*/

//verison 1(4 ms)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
    int helper (vector<int>& nums, int left, int right) {
    	if(left >= right) return left;
    	int mid1 = left + (right - left)/2;
    	int mid2 = mid1 + 1;
    	if(nums[mid1] < nums[mid2]) return helper(nums, mid2, right);
    	else return helper(nums, left, mid1);
    }
};