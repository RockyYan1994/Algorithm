/*
	由于可以无限次的交易，感觉就不停比较前一天的和当前的，如果增加则将当前的和上一个的差相减然后加到结果中。
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1]) ret += prices[i]-prices[i-1];
        }
        return ret;
    }
};