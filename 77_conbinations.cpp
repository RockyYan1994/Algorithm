/*
	first
	首先想到使用回溯法。
*/

//version 1(81 ms)
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> temp;
        backtracking(res,temp,1,n,k);
        return res;
    }
    void backtracking(vector<vector<int> > &res,vector<int> &temp,int b,int &n,int &k){
        if(temp.size()==k){
            res.push_back(temp);
            return;
        }
        for(int i=b;i<=n;i++){
            temp.push_back(i);
            backtracking(res,temp,i+1,n,k);
            temp.pop_back();
        }
    }
};

//version 2(from hengyi)
class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
		int i = 0;
		vector<int> p(k, 0);
		while (i >= 0) {
			p[i]++;
			if (p[i] > n) --i;
			else if (i == k - 1) result.push_back(p);
			else {
			    ++i;
			    p[i] = p[i - 1];
			}
		}
		return result;
	}
};