/*
	first
	首先想到通过array 的特性，遍历数组，把如果元素nums[i]!=i+1,并且nums满足条件非负数，小于nums数组长度，并且nums[nums[i]-1]!=i+1，那么久
	置换两个元素，并且循环执行操作，避免换到之前的地方导致出错。最后通过从头遍历，返回第一个不满足条件的元素，若都满足，则返回nums的长度
*/

//version 1(10 ms)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.empty()) return 1;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]>0&&nums[i]!=i+1&&nums[i]<nums.size()&&nums[nums[i]-1]!=nums[i]){
                cout<<nums[i]<<" ; "<<nums[nums[i]-1]<<endl;
                int temp = nums[i];
                nums[i] = nums[temp-1];
                nums[temp-1] = temp;
                while(nums[i]>0&&nums[i]!=i+1&&nums[i]<nums.size()&&nums[nums[i]-1]!=nums[i]){
                    int temp = nums[i];
                    nums[i] = nums[temp-1];
                    nums[temp-1] = temp;
                }
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1) return i+1;
        }
        return nums.size()+1;
    }
};

//version 2(4 ms)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.empty()) return 1;
        for(int i=nums.size()-1;i>=0;i--){
            while(nums[i]>0&&nums[i]!=i+1&&nums[i]<nums.size()&&nums[nums[i]-1]!=nums[i]){
                int temp = nums[i];
                nums[i] = nums[temp-1];
                nums[temp-1] = temp;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1) return i+1;
        }
        return nums.size()+1;
    }
};