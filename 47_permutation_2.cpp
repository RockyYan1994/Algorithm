/*
	first
	首先想到直接使用自带函数XD，其次用backtracking的方法应该也能实现。
	在首次实现backtracking的时候，backtracking函数采用了对nums的引用，同时在结束一次的时候采用再次swap的办法，但是无法处理【1，1，2，2】这样
	的情况，查看discussion之后发现，如果不采用引用的方法，就不会出现重复的情况，不过这个方法会消耗多一点空间，但是时间上会更少。
	还可以通过自己实现perumute的方法实现本题。见version 3
*/

//version1 (25 ms)
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int> > res;
        do{res.push_back(nums);}
        while(next_permutation(nums.begin(),nums.end()));
        return res;
    }
};

//version 2（27 ms）
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int> > res;
        backtracking(nums,res,0);
        return res;
    }
    void backtracking(vector<int> &nums,vector<vector<int> >& res,int begin){
        if(begin==nums.size()-1){
            res.push_back(nums);
            return;
        }
        for(int i=begin;i<nums.size();i++){
            if(i!=begin&&nums[begin]==nums[i]) continue;
            swap(nums[begin],nums[i]);
            backtracking(nums,res,begin+1);
            swap(nums[begin],nums[i]);
        }
    }
};

//version 3(from rubiknailer )
class Solution {
public:
	vector<vector<int> > permuteUnique(vector<int> &S) {
		// res.clear();
		sort(S.begin(), S.end());		
		res.push_back(S);
		int j;
		int i = S.size()-1;
		while (1){
			for (i=S.size()-1; i>0; i--){
				if (S[i-1]< S[i]){
					break;
				}
			}
			if(i == 0){
				break;
			}

			for (j=S.size()-1; j>i-1; j--){
				if (S[j]>S[i-1]){
					break;
				}
			}					
			swap(S[i-1], S[j]);
			reverse(S, i, S.size()-1);
			res.push_back(S);
		}
		return res;
    }
	void reverse(vector<int> &S, int s, int e){		
		while (s<e){
			swap(S[s++], S[e--]);
		}
	}
	
	vector<vector<int> > res;
};