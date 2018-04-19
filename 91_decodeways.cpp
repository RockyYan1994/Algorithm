/*
	first：首先想到利用条件1、2来判断，后来发现0时一个必须处理的元素，因为如果存在0，前面必须搭配一个1或者2，否则就需要返回0。查看discussion之后
	发现可以使用线性的空间完成DP的操作。
*/

//version 1(4 ms)
class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s[0]=='0') return 0;
        vector<int> dp(s.size()+1,1);
        for(int i=2;i<s.size()+1;i++){
            if(s[i-1] == '0') {
                if(s[i-2] == '0' || s[i-2] >='3') return 0;
                dp[i] = dp[i-2];
            }
            else if( (s[i-1] <='6'&& s[i-1]>='1' && s[i-2]=='2') || s[i-2] == '1') dp[i] = dp[i-1] + dp[i-2];
            else dp[i] = dp[i-1];
        }
        return dp[s.size()];
    }
};

//version 2(from other's)
int numDecodings(string s) {
    if (!s.size() || s.front() == '0') return 0;
    // r2: decode ways of s[i-2] , r1: decode ways of s[i-1] 
    int r1 = 1, r2 = 1;
    
    for (int i = 1; i < s.size(); i++) {
        // zero voids ways of the last because zero cannot be used separately
        if (s[i] == '0') r1 = 0;

        // possible two-digit letter, so new r1 is sum of both while new r2 is the old r1
        if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6') {
            r1 = r2 + r1;
            r2 = r1 - r2;
        }

        // one-digit letter, no new way added
        else {
            r2 = r1;
        }
    }

    return r1;
}