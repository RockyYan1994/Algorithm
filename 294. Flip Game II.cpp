/*
	方法一：采用DFS，如果遇到自己操作之后，对方无法胜利的情况，就返回true；时间复杂度
	方法二：采用DP， 减少重复计算。
*/

//version 1(44 ms)
class Solution {
public:
    bool canWin(string s) {
        int len = s.size();
        for(int i = 0; i < len-1; i++){
            if(s[i] == '+' && s[i+1] == '+'){
                s[i] = '-'; s[i+1] = '-'; 
                if(!canWin(s)) return true;
                s[i] = '+'; s[i+1] = '+';         
            }
        }
        
        return false;
    }
};

//version 2(8 ms)
class Solution {
public:
    bool canWin(string s) {
        unordered_map<string, bool> um;
        return helper(s, um);
    }
    
    bool helper(string s, unordered_map<string, bool>& um) {
        if (um.find(s) != um.end()) {
            return um[s];
        }
        int len = s.size();
        for(int i = 0; i < len-1; i++){
            if(s[i] == '+' && s[i+1] == '+'){
                string t = s.substr(0, i) + "--" + s.substr(i+2);
                bool res = !helper(t, um);
                if (res) {
                    um[s] = true;
                    return true;
                }
            }
        }       
        um[s] = false;
        return false;
    }
};