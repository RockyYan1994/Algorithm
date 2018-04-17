/*
	first
	首先想到用一个对应的数组，实现permutation，然后通过每次输出和该数组顺序相同的nums的数组就是当前序列结果，然后push到结果中，但是permutation数组没
	实现。。
	之前自己没想出来backtracking的实现方法，查看了discussion之后，发现有多种backtracking的实现方法，version2选择了其中一种逻辑简单的方法。
	还能直接调用next_permutation来实现。
*/

//version 1（X）
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> per;
        for(int i=0;i<nums.size();i++){
            per.push_back(i);
        }
        sort(nums.begin(),nums.end());
        int i;
        while(true){
            bool sign=false;
            for(i=nums.size()-2;i>=0;i--){
                if(per[i]<per[i+1]){
                    sign=true;
                    swap(per[nums.size()-1],per[i+1]);
                    sort(per.begin()+i,per.end());
                    // for(int j=i+2;j<nums.size();j++){
                    //     if(per[j]>per[i+1]) swap(per[i],per[j]);
                    // }
                    vector<int> temp;
                    for(int k=0;k<nums.size();k++) temp.push_back(nums[per[k]]);
                    res.push_back(temp);
                    // i=nums.size()-2;
                }
            }
            if(!sign) break;
        }
        
        return res;
        
    }
    
//     void backtracking(vector<int>& nums,vector<int>& temp){
        
//         for(int i=0;i<nums.size();i++){
            
//         }
//     }
};

//version 2(13 ms)
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        backtracking(nums,res,0);
        return res;
    }
    void backtracking(vector<int>& nums,vector<vector<int> >& res,int begin){
        if(begin==nums.size()-1){
            res.push_back(nums);
            return;
        }
        for(int i=begin;i<nums.size();i++){
            swap(nums[begin],nums[i]);
            backtracking(nums,res,begin+1);
            swap(nums[begin],nums[i]);
        }
    }
};

//version 3(12 ms)
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        sort(nums.begin(),nums.end());
        do{res.push_back(nums);}
        while(next_permutation(nums.begin(),nums.end()));
        return res;
    }
};