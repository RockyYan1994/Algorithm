/*
	first
	看了题目要求之后，想到要采用inplace，并且只遍历一次数组，因此想到利用两个变量，一个count0和一个count1来统计两个颜色的值，然后根据新出现的情况
	来通过变量更新。
	查看discussion之后，发现可以采用从两边往中间的方法来实现这个操作。
*/

//version 1(4 ms)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.empty()) return;
        int count0=0,count1=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                nums[i]=nums[count0+count1];
                nums[count0+count1] = nums[count0];
                nums[count0++] = 0;
            }
            else if(nums[i]==1){
                nums[i] = nums[count0+count1];
                nums[count0+count1++] = 1;
            }
            else{
                nums[i] = 2;
            }
        }
        return;
    }
};

//version 2(4 ms)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.empty()) return;
        int p0=0,p2=nums.size()-1;
        for(int i=0;i<=p2;i++){
            if(nums[i]==0){
                swap(nums[p0++],nums[i]);
            }else if(nums[i]==2){
                swap(nums[p2--],nums[i--]);
            }
        }
        return;
    }
};