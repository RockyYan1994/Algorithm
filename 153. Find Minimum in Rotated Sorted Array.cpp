/*
	方法一： 首先判定head 和 mid， 然后比较head 和 back。
	方法二： 可以线比较head 和back， 如果head比较小说明直接返回head就行。
*/

//verison 1(0.5 ms)
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty()) return 0;
        int head = 0;
        int back = nums.size()-1;
        int minValue = nums[0];
        while(head < back) {
            int mid = head + (back - head)/2;
            if(nums[head] <= nums[mid]) {
                if(nums[head] < nums[back]) return nums[head];
                else head = mid + 1;
            } else {
                back = mid;
            }
        }
        return nums[back];
    }
};