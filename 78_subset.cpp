/*
	first
	想到使用backtracking。
*/

//version1 (7 ms)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> temp;
        backtracking(res,temp,nums,0);
        return res;
    }
    void backtracking(vector<vector<int> > &res,vector<int> &temp,vector<int> &nums,int b){
        if(temp.size()<=nums.size()){
            res.push_back(temp);
        }
        for(int i=b;i<nums.size();i++){
            temp.push_back(nums[i]);
            backtracking(res,temp,nums,i+1);
            temp.pop_back();
        }
    }
};