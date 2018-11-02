/*
一开始想到用dp的方法，和连续加的最大和一样，但是发现由于乘法性质上的不同，并不能解决。
查看答案之后发现，可以维护一个最大值和最小值的两个变量，由于乘法的特性，如果乘一个负数，可能结果会从最小变到最大。
*/

//version 1(4 ms)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        int max_prod = nums[0];
        int min_prod = nums[0];
        int res = nums[0];
        
        for(int i=1;i< nums.size();i++) {
            if(nums[i] < 0) swap(max_prod,min_prod);
            
            max_prod = max(max_prod*nums[i], nums[i]);
            min_prod = min(min_prod*nums[i], nums[i]);
            
            res = max(res, max_prod);
        }
        return res;
    }
};