/*
	方法一：通过dp实现，在当前i的时候，求dp[i-1*1]+1, dp[i-2*2]+1......dp[i-sqrt(i)*sqrt(i)]的最小值。
*/

//version 1(60 ms)
class Solution {
public:
    int numSquares(int n) {
        vector<int> squares = findSquares(n);
        vector<int> dp(n+1, INT_MAX);
        
        for (int i=1; i<=n; i++) {
            int sqr = (int)sqrt(i);
            if (sqr * sqr == i) dp[i] = 1;
            for (int j=0; j<sqr; j++) {
                if (dp[i-squares[j]] == INT_MAX) continue;
                dp[i] = min(dp[i], dp[i-squares[j]] + 1);
            }
        }
        return dp[n];
    }
    
    vector<int> findSquares(int n) {
        vector<int> sqrs;
        for (int i=1; i*i <= n; i++) {
            sqrs.push_back(i*i);
        }
        return sqrs;
    }
};