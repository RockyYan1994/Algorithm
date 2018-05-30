/*
*	想到采用递归的方法，分别进行两次判断，采用一个标记值来指向当前每个string进行到的位置。但是这个解法效率太低。
*	查看了discussion发现可以采用DP的方法，使用一个二维bool数组，DP[i][j]，表示在s1的i位置和s2的j位置的时候是否能够满足到达s3的i+j的位置的情况。
*	
*/

//version 1(1271 ms)
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        bool ret = isInterleave(s1,s2,s3,0,0,0);
        return ret;
    }
    bool isInterleave(string& s1, string& s2, string& s3, int x, int y, int z){
        if(x == s1.size() && y == s2.size() && z == s3.size()) return true;
        bool ret = false;
        if(x<s1.size() && s1[x] == s3[z]) ret = isInterleave(s1,s2,s3,x+1,y,z+1);
        if(y<s2.size() && s2[y] == s3[z] && !ret) ret = isInterleave(s1,s2,s3,x,y+1,z+1);
        return ret;
    }
};

//version 2(4 ms)
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size() != s3.size()) return false;
        vector<vector<bool> > dp(s1.size()+1,vector<bool>(s2.size()+1,false)) ;
        dp[0][0] = true;
        for(int i=0;i<=s1.size();i++){
            for(int j=0;j<=s2.size();j++){
                if(i!=0) dp[i][j] = ( dp[i-1][j] && s1[i-1] == s3[i+j-1] ) || dp[i][j];
                if(j!=0) dp[i][j] = ( dp[i][j-1] && s2[j-1] == s3[i+j-1] ) || dp[i][j];
            }
        }
        return dp[s1.size()][s2.size()];
    }    
};