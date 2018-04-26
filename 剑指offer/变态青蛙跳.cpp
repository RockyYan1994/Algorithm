/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法
	首先想到的方法是使用动态规划，通过两次循环来实现，查看讨论发现通过总结，当n>=2时，可以采用f(n) = 2*f(n-1) 计算。
*/

//version 1（3 ms）
class Solution {
public:
    int jumpFloorII(int number) {
        if(number == 0)return 0;
        vector<int> dp(number+1,1);
        for(int i=2;i<=number;i++){
            int temp = 0;
            for(int j=0;j<i;j++){
                temp += dp[j];
            }
            dp[i] = temp;
        }
        return dp[number];
    }
};

//version 2（3 ms）
class Solution {
public:
    int jumpFloorII(int number) {
        if(number == 0)return 0;
        vector<int> dp(number+1,1);
        for(int i=2;i<=number;i++){
            dp[i] = dp[i-1] * 2;
        }
        return dp[number];
    }
};