/*
	first；
	自己做没想出来o(n)解法，
	概念主要在于结束点不动，如果前面的为正则加上，否则不加。
	可以看作DP问题，但是不方便采用递归的方式来完成。
*/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int final_max = nums.at(0);
        int cur_max = 0;
        for(int i=0;i<nums.size();i++){
            cur_max = cur_max>=0?cur_max+nums.at(i):nums.at(i);
            final_max = max(final_max,cur_max);
        }
        return final_max;
    }
};