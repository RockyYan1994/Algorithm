/*
	方法一：最简单，直接采用排序之后寻找。
	方法二：用和桶排序类似的方法
	方法三：用异或实现
*/

//version 1(20 ms)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int miss = -1;
        sort (nums.begin(), nums.end()) ;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] != i) return i;
        }
        return nums.size();
    }
};

//version 2(16 ms)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> vec(nums.size()+1, -1);
        for (auto num : nums) {
            vec[num] = 1;
        }
        for (int i=0; i<vec.size(); i++) {
            if (vec[i] == -1) return i;
        }
        return -1;
    }
};

//version 3(16 ms)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size();
        for (int i=0; i<nums.size(); i++) {
            res ^= i;
            res ^= nums[i];
        }
        return res;
    }
};