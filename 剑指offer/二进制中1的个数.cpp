/*
二进制中1的个数
首先想到直接用移位的方法，但是发现不对，因为右移带符号位的话可能会造成无限个1.当然还可以用一个flag数，不断右移和n比较计算。

*/
//version 1（wrong）
class Solution {
public:
     int  NumberOf1(int n) {
         int count = 0;
         while(n!=0){
             if(n & 1) count++;
             n = n>>2;
         }
         return count;
     }
};

//verion 2（4 ms）
class Solution {
public:
     int  NumberOf1(int n) {
         int count = 0;
         while(n!=0){
             count++;
             n = (n-1)&n; //n-1表示把最右边的1变成0
         }
         return count;
     }
};