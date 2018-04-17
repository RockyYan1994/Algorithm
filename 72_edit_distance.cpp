/*
	first
	首先想到使用短一点的子串和长一点的子串进行比较，找出最大的相应字符长度，然后通过增删来实现转换。结果发现并不能实现，因为对应最大字符长度无法准确得出
	查看discussion之后发现这是一个典型的DP问题，在实现的时候查看了discussion的情况，发现可以采用空间O（mn）来实现，也可以采用空间O（max（m，n））
	实现，version1采用了O（mn）实现。version2采用了O（max（m，n））的方法。

*/

//version 1(12 ms)
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int> > dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<m+1;i++){
            dp[i][0] = i;
        }
        for(int i=0;i<n+1;i++){
            dp[0][i] = i;
        }
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }    
                else{
                    dp[i][j] = min(dp[i-1][j-1]+1,min(dp[i][j-1]+1,dp[i-1][j]+1));
                }
            }
        }
        return dp[m][n];
    }
};



//version 2( from jianchaolifighter)
class Solution { 
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<int> cur(m + 1, 0);
        for (int i = 1; i <= m; i++)
            cur[i] = i;
        for (int j = 1; j <= n; j++) {
            int pre = cur[0];
            cur[0] = j;
            for (int i = 1; i <= m; i++) {
                int temp = cur[i];
                if (word1[i - 1] == word2[j - 1])
                    cur[i] = pre;
                else cur[i] = min(pre + 1, min(cur[i] + 1, cur[i - 1] + 1));
                pre = temp;
            }
        }
        return cur[m]; 
    }
}; 