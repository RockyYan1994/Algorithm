/*
	first
	根据题，最先想到的是最基本的（most silly）方法，遍历+比较。
	根据题意，感觉可以使用二分查找，然是array并不是连续的，因此不能通过第一个元素直接确定后面的元素个数，。因此只有通过条件判断实现二分查找。首先想到
	判断条件是nums第一个数字，通过比较久能够得到是否是rotated。
	结果实现和之前想的差别很大，实现是利用了所有可能出现在右边的情况，实现head=mid+1的操作，别的情况全部使用back = mid-1，通过附加条件的二分查找实现
	。
	查看了discussion之后发现，可以先找到最小值所在位置min_pos，然后通过常规的binary search查找元素，在二分查找的时候通过元素的mid+min_pos%nums.size()
	的方法找到实际上的中值，其实久相当于一个平移。
	看了discussion发现，可以实现之前的一个想法，就是把最常规的情况找出，然后剩下的情况必然是归于另一类，实际上就是将和binary search常规的判定提取
	出来。version 3
*/

//version 1(9 ms)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int i=0; i<nums.size();i++){
            if(nums[i]==target) return i;
        }
        return -1;
    }
};

//version 2(7 ms)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int head=0,back=nums.size()-1,mid;
        
        while(head<=back){
            mid = head + (back-head)/2;
            if(nums[mid]==target) return mid;
            else if(nums[head]==target) return head;
            else if(nums[back]==target) return back;
            else if(nums[mid]<target&&nums[back]>target) head = mid + 1;
            else if(nums[mid]<target&&nums[back]<target&&nums[back]<nums[mid]) head = mid + 1;
            else if(nums[mid]>target&&nums[back]>target&&nums[back]<nums[mid]) head = mid + 1;
            else back = mid - 1;
        }
        return -1;
    }
};
//version 3 (7 ms)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int head=0,back=nums.size()-1,mid;
        
        while(head<=back){
            mid = head + (back-head)/2;
            if(nums[mid]==target) return mid;
            if(nums[head]<=nums[mid]){
                if(nums[mid]>target&&nums[head]<=target) back = mid - 1;
                else head = mid + 1;
            }
            else{
                if(nums[mid]<target&&nums[back]>=target) head = mid + 1;
                else back = mid - 1;
            }
        }
        return -1;
    }
};