/*
	方法一：采用一个rev表示大小关系。
	方法二：直接用i%2来代替rev。
*/

//version 1(
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if (nums.empty()) return;
        bool rev = false;
        for (int i=0; i<nums.size()-1; i++) {
            if (rev && nums[i] < nums[i+1] || !rev && nums[i] > nums[i+1]) swap(nums[i], nums[i+1]);
            rev = !rev;
        }        
    }
};