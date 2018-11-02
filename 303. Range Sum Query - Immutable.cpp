/*

*/

//version 1(112 ms)
class NumArray {
    vector<int> sums;
public:
    NumArray(vector<int> nums) {
        int sum = 0;
        for (int i=0; i<nums.size(); i++) {
            sum += nums[i];
            sums.push_back(sum);
        }
    }
    
    int sumRange(int i, int j) {
        return i>0 ? sums[j] - sums[i-1] : sums[j];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */