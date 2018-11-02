/*

*/

//version 1(4 ms)
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;
        int n = costs.size();
        vector<vector<int>> dp(n, vector<int>(3, INT_MAX));
        dp[0] = costs[0];
        for (int i=1;i<n; i++) {
            dp[i][0] = costs[i][0] + min(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = costs[i][1] + min(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = costs[i][2] + min(dp[i-1][0], dp[i-1][1]);
        }
        return min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
    }
};

//version 2(4 ms)
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;
        int n = costs.size();
        vector<int> price(costs[0]);        
        for (int i=1;i<n; i++) {
            vector<int> lastPrice(price);
            price[0] = costs[i][0] + min(lastPrice[1], lastPrice[2]);
            price[1] = costs[i][1] + min(lastPrice[0], lastPrice[2]);
            price[2] = costs[i][2] + min(lastPrice[0], lastPrice[1]);
        }
        return min(price[0], min(price[1], price[2]));
    }
};