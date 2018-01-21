/*
	first
	首先考虑到的是排序，然后判定到相等的地方，然后进行操作。想到从后面往前遍历，如果遇到和val相同的值，就和当前i进行交换。
*/

//version 1(6 ms)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]==val) nums[i] = nums[(nums.size()-1)-(count++)];
        }
        return nums.size()-count;
    }
};