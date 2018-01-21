/*
    first
    首先想到最简单的算法，将其转换成string， 通过string从开头和结尾比较，如果不同则返回false，执行效率比较低
    优化思想：考虑回文特性，看是否存在算法能够直接得出结论。
    版本2采用对数字进行处理的方法来进行比较，首先保存x的值，然后通过取余+乘10的方法reverse，最后进行比较，返回比较结果，这个方法不用考虑overflow
    因为在进行比较的过程中已经进行了验证，如果已经有overflow的话，比较结果就会为false。
*/
//version 1(291 ms)(11510 test cases).  提前判断x是否为负数（221 ms）
class Solution {
public:
    bool isPalindrome(int x) {
        stringstream ss;
        ss<<x;
        string str;
        ss>>str;
        int i=0;
        if(str[0]=='-') return false;
        for(int j=str.size()-1;i<j;i++,j--){
            if(str[i]!=str[j]) return false;
        }
        return true;
    }
};

//version 2(170 ms)
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int rev = 0;
        int temp = x;
        while(x>0){
            rev = rev*10 + x%10;
            x /= 10;
        }
        return temp==rev;
    }
};