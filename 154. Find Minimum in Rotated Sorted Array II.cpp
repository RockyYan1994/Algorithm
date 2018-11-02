/*
	需要注意mid小于back的时候，mid可能是最小值，所以应该吧back置为mid
*/

// version 1()
class Solution {
public:
    int findMin(vector<int>& nums) {
        int head = 0;
        int back = nums.size()-1;
        while(head < back) {
            int mid = head + (back - head)/2;
            if(nums[mid] < nums[back]) back = mid;
            else if(nums[mid] > nums[back]) head = mid + 1;
            else back--;
        }
        return nums[back];
    }
};