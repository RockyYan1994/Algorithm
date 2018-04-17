/*
	first
	首先想到采用多次循环来进行选择，但是发现不能够有效的实现去掉相同序列的操作，在每一次寻找的时候，不能有效的避免进入上一次找到的情况。
	在查看discussion之后， 发现了可以使用backtracking（回溯法）的方法来实现，http://www.dreamxu.com/books/dsa/backtracking/index.html。
	回溯法的核心在于一个不停调用一个函数，当到达某一个解或者违反了部分规则的时候，返回上一层。适合用在需要遍历所有情况，同时没有重复发生的条件下使用。

	在version3中第22行调用sumCombination函数的时候卡了一万年，因为最后一个参数传的是begin+1，最后改成了i+1才通过。
*/

//version 1（abandoned）
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        int pos=candidates.size()-1;
        int tar = target;
        for(int i=candidates.size()-1;i>=0;i--){
            if(target<candidates[i]) continue;
            
            while(true){
                vector<int> cur_seq; 
                target = tar;
                for(int j=i;i>=0;i--){
                    if(target>candidates[j]) {
                        target -= candidates[j];
                        cur_back.insert(candidates.begin(),candidates[j]);
                    }
                }
                if(target==0) res.push_back(cur_seq);
            }
            
        }
    }
};

//version 2 (12 ms)
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int> > res;
        vector<int> temp;
        backtrackingCombination(res,candidates,temp,target,0);
        return res;
    }
    
    void backtrackingCombination(vector<vector<int> > &res,vector<int> &candidates,vector<int> &temp,int target,int back){
        if(target==0){
            res.push_back(temp);
            return;
        }
        for(int i=back;i<candidates.size()&&candidates[i]<=target;i++){
            temp.push_back(candidates[i]);
            backtrackingCombination(res,candidates,temp,target-candidates[i],i);
            temp.pop_back();
        }
    }
};

//version 3（15 ms）
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int> > res;
        vector<int> temp;
        sumCombination(res,candidates,temp,target,0);
        return res;
    }
    
    void sumCombination(vector<vector<int> > &res,vector<int> &candidates,vector<int> &temp,int target,int begin){
        if(target<0) return;
        if(target==0) {
            res.push_back(temp);
            return ;
        }
        if(candidates[begin]>target) return;
        for(int i=begin;i<candidates.size();i++){
            int c=1;
            while(target>=(c*candidates[i])){
                temp.push_back(candidates[i]);
                sumCombination(res,candidates,temp,target-c*candidates[i],i+1);
                c++;
            }
            while(c!=1){
                temp.pop_back();
                c--;
            }
        }
    }
};