/*
	方法一：通过start和end来track连续的情况，当连续就更新end。如果不满足则输入，判断start<end 就是连续的情况。
	方法二：通过往后遍历，第一个不满足情况的停下，和开始比较。
*/

//version 1()
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int start = 0, end = 0;
        vector<string> res;
        for (int i=0; i<nums.size(); i++) {
            if ( i!=nums.size()-1 && nums[i] + 1 == nums[i+1]) {
                end = i + 1;
            } else {
                if(start < end) {
                    res.push_back(continuous(start, end, nums));                    
                } else {
                    res.push_back(to_string(nums[i]));
                }
                start = i + 1;
            }                     
        }
        return res;
    }
    
    string continuous(int start, int end, vector<int>& nums) {
        return to_string(nums[start]) + "->" + to_string(nums[end]);
    }
};

//versionn 2()
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        for (int i=0;i<nums.size();i++) {
            int a = nums[i];
            int j = i;
            while (nums[j+1] - a == j - i + 1) j++;
            if(nums[j] == a) res.push_back(to_string(nums[i]));
            else res.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
            i = j;
        }
        return res;
    }
};