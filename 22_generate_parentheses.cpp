/*
	first
	自己想没想出来具体实现，想过递归，想过DP，但是都没想通怎么实现，惊了，参考过discussion之后写出递归实现，

	backtrack感觉是一个通用的方法，
*/
//version 1(3 ms)
class Solution {
public:
    vector<string> generateParenthesis(int n) {
       vector<string> res;
        backtrack(res,"",0,0,n);
        return res;
    }
    
    void backtrack(vector<string>& res,string str,int open,int close,int max){
        if(str.size()==2*max){
            res.push_back(str);
        }
        if(open<max){
            backtrack(res,str+'(',open+1,close,max);
        }
        if(close<open){
            backtrack(res,str+')',open,close+1,max);
        }
    }
};