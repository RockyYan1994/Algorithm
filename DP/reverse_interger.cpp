/*
    first
    首先想到用取余数然后加到新的int变量上，每次加到变量的时候将原有的变量乘10. 对于overflow的处理首先采用判断之前结果是否大于INT_MAX/10 or 
    小于INT_MIN/10。但是由于进行了除法运算，导致程序运行速度降低，根据参考，采用运算之前和运算之后结果/10的结果进行比较，如果结果不同就说明溢出。

    优化思路，判定溢出可以采用更加简易方法。
*/
//version 1(20 ms)
class Solution {
public:
    int reverse(int x) {
        int ret=0;
        while(x!=0)
        {
            int temp = ret*10 + x%10;
            if(temp/10 != ret) return 0;
            ret = temp;
            x /= 10;
        }
        return ret;
    }
};