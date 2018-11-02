


//version 1(Wrong in below test)
/*
[2147483647]
0
2147483647
*/
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> output;        
        int len = nums.size() - 1;
        int i = 0;
        int next=lower;
        for(;i<nums.size();i++) {
            if(nums[i] < next) continue;
            if(nums[i] == next) {
                next++;
                continue;
            }
            output.push_back(formatHelper(next, nums[i]-1));
            next = nums[i] + 1;
        }
        if(next<=upper) output.push_back(formatHelper(next, upper));
        return output;
    }
    string formatHelper(int left, int right) {
        return left==right ? to_string(left) : to_string(left)+"->"+to_string(right);
    }
};