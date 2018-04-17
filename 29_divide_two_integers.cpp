/*
	first
	首先想到使用直接减的方法。但是这个方法效率太低。需要使用采用位运算实现，在首次实现想使用将divisor放缩到最大再缩放到原始的方法，但是始终不能通过，
	好像有的情况始终不能完整的适配，查看discussion之后发现可以使用每次都匹配的方法，在循环中添加一次循环来实现。

	发现在做类似题目的时候需要关注边界量的问题，特别是位运算XD。
*/

//version 1 (cannot pass)
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0) return 0;
        if(divisor==-1 && dividend==INT_MIN) return INT_MAX;
        if(dividend ==INT_MIN && divisor == 1) return INT_MIN;
        bool sign = (dividend>0 ^ divisor>0)?false:true;
        long long ded = labs(dividend);
        long long dor = labs(divisor);
        int mul = 1;
        int res = 0;
        
        while(ded>(dor<<1)){
            dor <<= 1;
            mul <<= 1;
        }
        
        do{
            if(ded >= dor) {
                ded -= dor;
                res += mul;
            }
            dor >>= 1;
            mul >>= 1;
        }while(ded>0 && mul>=1);
        return sign?res:-res;
    }
};
//version 2(18 ms)
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0) return 0;
        if(divisor==-1 && dividend==INT_MIN) return INT_MAX;
        //if(dividend ==INT_MIN && divisor == 1) return INT_MIN;
        bool sign = (dividend>0 ^ divisor>0)?false:true;
        long long ded = labs(dividend);
        long long dor = labs(divisor);
        int res = 0;
        
        while(ded >= dor){
            long long mul=1, temp = dor;
            while(ded>=(temp<<1)){
                mul<<=1;
                temp<<=1;
            }
            res += mul;
            ded -= temp;
        }
        return sign?res:-res;
    }
};