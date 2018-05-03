/*
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
发现了评论去一个采用异或和与的方法：
	1，通过num1和num2异或计算不算上进位的加法；
	2，通过num1和num2同或并且左移移位来计算进位的值；
	3，不断重复一二步知道num2为零
*/

class Solution {
public:
    int Add(int num1, int num2)
    {
        while(num2){
            int temp = num1^num2;
            num2 = (num1&num2)<<1;
            num1 = temp;
        }
        return num1;
    }
};