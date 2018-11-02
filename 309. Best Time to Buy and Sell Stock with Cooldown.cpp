/*
	方法一：采用DP，用一个hold记录当前有股票在手的状态，一个unhold表示当前无股票在手的状态
	方法二：优化·空间复杂度。通过preBuy和preSell保存之前的状态，每次交叉更新。
*/

//version 1(4 ms)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int n = prices.size(), res = 0;        
        vector<int> hold(n, 0), unhold(n, 0);
        hold[0] = -prices[0];
        hold[1] = -min(prices[0],prices[1]);
        unhold[1] = max(prices[1] - prices[0], 0);
        for (int i=2; i<n; i++) {
            hold[i] = max(hold[i-1], unhold[i-2] -prices[i]);
            unhold[i] = max(unhold[i-1], hold[i-1]+prices[i]);
        }
        return unhold[n-1];
    }
};

//version 2(4 ms)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int n = prices.size(), res = 0;        
        int preBuy, buy = -prices[0], preSell = 0, sell = 0;
        for (int i=0; i<n; i++) {
            preBuy = buy;
            buy = max(preSell-prices[i], buy);
            preSell = sell;
            sell = max(preBuy+prices[i], sell);
        }
        return sell;
    }
};