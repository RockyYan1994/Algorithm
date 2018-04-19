/*
    first: 首先想到使用subsets来实现，由于没有排序，造成了结果出错。在查看了discussion之后，发现可以采用一个统计相同数的方法，通过统计当前的
    相同元素数量，分别添加1 - k的数量的当前元素进之前的所有向量中（并不覆盖之前的结果）。结果发现backtracking比第一个方法快许多。第三种方法
    通过判断新的数和上一个是否相同来决定从0添加还是从上上一次的末尾添加。
*/
//version 1(15 ms)
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > res = {{}};
        sort(nums.begin(),nums.end());
        int i;
        for(i=0;i<nums.size();){
            int count = 0;
            while(i+count<nums.size() && nums[i] == nums[i+count]) count++;
            int m = res.size();
            for(int j=0;j<m;j++){
                vector<int> temp = res[j];
                for(int k=0;k<count;k++){
                    temp.push_back(nums[i]);
                    res.push_back(temp);
                }
            }
            i += count;
        }
        return res;
    }
};

//version 2(9 ms from other's answer)
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if(n == 0)
        {
            return res;
        }
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        solve(res, tmp, nums, 0);
        return res;
    }
    void solve(vector<vector<int>>& res, vector<int>& tmp, vector<int>& nums, int start)
    {
        res.push_back(tmp);
        for(int i = start; i < nums.size(); i++)
        {
            if(i > start && nums[i] == nums[i-1])
            {
                continue;
            }
            tmp.push_back(nums[i]);
            solve(res, tmp, nums, i + 1);
            tmp.pop_back();
        }
    }
};

//version 3(10 ms from other's)
class Solution { 
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > res(1, vector<int>());
        int sz = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            int idx = ((i >= 1 && nums[i] == nums[i - 1]) ? sz : 0);
            sz = res.size();
            for (int j = idx; j < sz; j++) {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        return res;
    } 
};