

//version 1(4 ms)
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> num2cnt;
        for (auto num : nums1) {
            num2cnt[num]++;
        }
        vector<int> res;
        for (auto num : nums2) {
            if (num2cnt[num] > 0) {
                res.push_back(num);
                num2cnt[num]--;
            }
        }
        return res;
    }
};