/*

*/

//version 1(8 ms)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        vector<int> res;
        for (auto num : nums2) {
            if(s1.count(num)!=0) {
                res.push_back(num);
                s1.erase(num);
            }
        }
        return res;      
    }
};

//version 2(4 ms)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s(nums1.begin(), nums1.end());
        vector<int> out;
        for (int x : nums2)
            if (s.erase(x))
                out.push_back(x);
        return out;
    }
};