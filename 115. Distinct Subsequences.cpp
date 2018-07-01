/*
	首先想到用backtracking的方法来实现，但是始终不能通过，EG（s：rabbbit，t：rabbit），查看了discussion之后，发现能够采用dp的方法来实现。
	dp还能够通过精简，采用一维的方法实现。
*/

//version 1(error)
class Solution {
public:
    int numDistinct(string s, string t) {
        int count = 0;
        backtracking(s,t,0,0,count);
        return count;
    }
    void backtracking(const string& s, const string& t, int s_start, int t_start, int& count)
    {
        if(t.size()-t_start > s.size()-s_start || t_start >= t.size() || s_start >= s.size() ) return;
        if( s[s_start] == t[t_start] && t_start == t.size()-1 ){
            count++;
            return;
        }
        for(int i=s_start;i<s.size();i++){
            if(s[i] == t[t_start]) backtracking(s,t,i+1,t_start+1,count);
            backtracking(s,t,i+1,t_start,count);
        }
    }
};


//version 2(6 ms)
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<int> > dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=m;i++) dp[0][i] = 1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)
                dp[i][j] = dp[i][j-1] + (t[i-1] == s[j-1] ? dp[i-1][j-1]:0);
        }
        return dp[n][m];
    }
};