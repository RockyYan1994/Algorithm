/*
	first
	顺序数组中找元素的问题，一开始想到使用二分查找的方法，但是在查找不到的情况下，需要通过结束位置的元素判断最终返回值的问题。
*/
//version 1(8 ms)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int res=0;
        
        int head = 0, back = nums.size()-1;
        while(head<=back){
            int mid = head + (back-head)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) head = mid+1;
            else back = mid-1;
        }
        return (nums[head]>target||head>=nums.size())?head:head+1;
    }
};