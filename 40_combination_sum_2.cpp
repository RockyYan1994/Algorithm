/*
	first
	和39问题类似，但是一直不是特别理解为什么第33行是i>begin，发现解释如下。

	cuyuan May 25, 2016, 7:54 PM
	For those who don’t understand how to avoid duplicate by:
	if "(i > cur && cand[i] == cand[i-1]) continue;
	when we should skip a number? not just it’s the same as previous number, but also when it’s previous number haven’t 
	been added!i > cur means cand[i - 1] is not added to the path (you should know why if you 
	understand the algorithm), so if cand[i] == cand[i-1], then we shouldn’t add cand[i].

	This tricky is very smart.
*/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        vector<vector<int> > res;
        backtrackingSum(res,candidates,temp,target,0);    
        return res;
    }
    void backtrackingSum(vector<vector<int> > &res,vector<int> &candidates,vector<int> & temp, int target,int begin){
        if(target==0){
            cout<<begin<<endl;
            res.push_back(temp);
            return;
        }
        if(target<0) return;
        for(int i=begin;i<candidates.size();i++){
            cout<<"begin is "<<begin<<" ; "<<"i is "<<i<<endl;
            if(candidates[i]==candidates[i-1]&&i>begin) continue;
            if(target>=candidates[i]){
                temp.push_back(candidates[i]);
                backtrackingSum(res,candidates,temp,target-candidates[i],i+1);
                temp.pop_back();
            }
        }
    }
};