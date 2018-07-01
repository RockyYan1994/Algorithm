/*
	利用了两个数字异或为零的性质。
*/

//version 1(15 ms)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = nums[0];
        for(int i=1;i<nums.size();i++) ret ^= nums[i];
        return ret;
    }
};