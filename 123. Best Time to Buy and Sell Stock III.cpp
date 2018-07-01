/*
	主要采用DP的思想，k代表交易次数，i代表当前的日期。
*/

//version 1(8 ms)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        vector<vector<int> > dp(3, vector<int>(prices.size(),0));
        
        for(int k=1;k<dp.size();k++){
            int tempMin = prices[0];
            for(int i=0;i<dp[0].size();i++){
                tempMin = min(tempMin, prices[i] - dp[k-1][i-1]);
                dp[k][i] = max(dp[k][i-1],prices[i] - tempMin);
            }
        }
        return dp[2][prices.size()-1];
    }
};