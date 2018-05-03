/*
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
一开始想用移位来运算，查看discussion之后发现还有递归的方法。
*/
//version 1(4 ms )
class Solution {
public:
    int Sum_Solution(int n) {
        int ret = n;
        ret && (ret+=Sum_Solution(n-1));
        return ret;
    }
};

//version 2(3 ms)
class Solution {
public:
    int Sum_Solution(int n) {
        int ret = 0, a=n, b=n+1;
        while(a){
            if(a&1) ret+=b;
            a>>=1;
            b<<=1;
        }
        ret >>= 1;
        return ret;
    }
};