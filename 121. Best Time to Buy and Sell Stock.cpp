/*
	主要就是通过一个min记录最低的收购价格，每次读入下一个价格的时候，如果比当前值小，则替换min，反之则计算当前值和min的差值，然后看是否更新maxProfit
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT_MAX, maxProfit = 0;
        for(int i=0;i<prices.size();i++){
            if(min > prices[i]) min = prices[i];
            else maxProfit = max(maxProfit, prices[i]-min);
        }
        return maxProfit;
    }
};