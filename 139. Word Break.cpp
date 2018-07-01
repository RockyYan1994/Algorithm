/*
	通过动态规划，dp[i]截止到i是否满足条件，外部循环i从0到s的长度，内部循环遍历每个单词的长度并且截取出来和wordDict中对应的单词比较。
*/

//version 1(6 ms)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.empty()) return true;
        vector<bool> dp(s.size()+1,false);
        dp[0] = true;
        for(int i=0;i<s.size();i++){
            for(int j=0;j<wordDict.size();j++){
                if(dp[i]){
                    string word = s.substr(i,wordDict[j].size());
                    if(word == wordDict[j]) dp[ i + wordDict[j].size() ] = true;
                }
            }
        }
        return dp[s.size()];
    }
};