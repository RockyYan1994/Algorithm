
//最简单的方法是通过从两边往中间检查，找到适合的值。
//version 1(4 ms)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> um;
        vector<int> res;
        for(int i=0;i<numbers.size();i++) {
            if(um.find(numbers[i]) != um.end()) {
                res.push_back(um[numbers[i]] + 1);
                res.push_back(i+1);
                break;
            }
            um[target-numbers[i]] = i;
        }
        return res;
    }
};