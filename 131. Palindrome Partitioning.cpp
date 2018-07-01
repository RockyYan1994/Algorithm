/*
	首先想到backtracking 的方法，但是在每一次循环的时候采用起点和长度的方法，并且判定是否为Palindrome，如果为真则递归调用。
*/

//version 1(7 ms)
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        if(s.empty()) return ret;
        
        vector<string> temp;
        backtracking(ret, temp, 0, s);
        return ret;
    }
    void backtracking(vector<vector<string>>& ret, vector<string>& temp, int index, string& s){
        if(index == s.size()) {
            ret.push_back(temp);
            return;
        }
        for(int i=0; index+i<s.size() ;i++){
            if(isPalindrome(s, index, index+i)){
                temp.push_back(s.substr(index,i+1));
                backtracking(ret, temp, index+i+1, s);
                temp.pop_back();
            }
        }
    }
    bool isPalindrome(string& s, int start, int end){
        while(start<end){
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
};