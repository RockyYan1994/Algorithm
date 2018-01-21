/*
	first
	首先想到使用一次遍历，然后利用erase的方法来实现。但是效率非常低下。（因为数组的删除的时间为O（n））
	优化思路，想到减少使用erase的次数，用一个内部循环来count，如果有多个相同值的情况下，只使用一个erase。
	看了discussion之后，发现只需要返回一个前面都为不重复的数组，这样就能够直接将不重复的值移动到前面，在遍历的时候将后面非重复的元素移动到前方。实现就使用count
	记录重复的元素。然后使用nums[i-count] = nums[i]来实现。
	查看了discussion之后，发现有另外的loop方法（version 4）。
*/

//version 1(52 ms)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	for(int i=1;i<nums.size();i++){
    		if(nums[i]==nums[i-1]) nums.erase(nums.begin()+i);
        	else i++;
    	}
        
        return nums.size();
    }
};

//version2（45 ms）
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j;
        for(int i=0;i<nums.size();){
            for(j=i+1;j<nums.size();j++){
                if(nums[i]!=nums[j]) break;
            }
            if(i!=j) {
                nums.erase(nums.begin()+i+1,nums.begin()+j);
            }
            i++;
        }
        return nums.size();
    }
};

//version 3(26ms)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]) count++;
            else nums[i-count] = nums[i];
        }
        return nums.size()-count;
    }
};

//version 4(26 ms)(author:stefanpochmann)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = !nums.empty();
        for (int n : nums)
            if (n > nums[i-1])
                nums[i++] = n;
        return i;
    }
};