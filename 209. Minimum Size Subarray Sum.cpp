/*
	1, O(n)的方法，主要通过一个sum来记录当前的和，如果大于s，则不断减去前面的元素。
*/

//version 1(12 ms)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int start = 0, sum = 0, minLen = nums.size()+1;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            while(sum >= s){
                minLen = min(minLen, i-start+1);
                sum -= nums[start++];
            }
        }
        return minLen > nums.size() ? 0 : minLen;
    }
};