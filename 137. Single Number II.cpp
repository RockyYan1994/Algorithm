/*
	通过状态机的方法，三个状态分别为00，01，10.通过两个变量进行转换。
*/

//version 1(10 ms)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
         int ones = 0, twos = 0;
        for(int i=0;i<nums.size();i++){
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;
        }
        return ones;
    }
};