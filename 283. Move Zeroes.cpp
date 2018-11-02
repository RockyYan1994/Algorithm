/*

*/

//version 1(8 ms)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for (auto num : nums) {
            if (num) nums[i++] = num;
        }
        for (int j = i; j<nums.size(); j++) {
            nums[j] = 0;
        }        
    }
};