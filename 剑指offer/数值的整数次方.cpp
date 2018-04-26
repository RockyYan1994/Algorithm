/* 
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
链接：https://www.nowcoder.com/questionTerminal/1a834e5e3e1a4b7ba251417554e07c00
来源：牛客网

【分析】
第一种方法：使用递归，时间复杂度O(logn)
当n为偶数，a^n =（a^n/2）*（a^n/2）
当n为奇数，a^n = a^[(n-1)/2] * a^[(n-1)/2] * a
举例：
2^11 = 2^1 * 2^2 * 2^8
2^1011 = 2^0001 * 2^0010 * 2^1000

第二种方法：累乘，时间复杂度为O(n)
*/

class Solution {
public:
    double Power(double base, int exponent) {
        double r = 1.0;
        int e = abs(exponent);
        while(e){
            if(e & 1) r *= base;
            base *= base;
            e >>= 1;
        }
        return exponent>0?r:1/r;
    }
};