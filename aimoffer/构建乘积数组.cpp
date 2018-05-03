/*
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法
查看了discussion，发现可以通过两次循环来解决这个问题。
链接：https://www.nowcoder.com/questionTerminal/94a4d381a68b47b7a8bed86f2975db46
来源：牛客网
From 张佃鹏 
第一步：b[0] = 1;
第二步：b[1] = b[0] * a[0] = a[0]
第三步：b[2] = b[1] * a[1] = a[0] * a[1];
第四步：b[3] = b[2] * a[2] = a[0] * a[1] * a[2];
第五步：b[4] = b[3] * a[3] = a[0] * a[1] * a[2] * a[3];
然后对于第二个for循环
第一步
temp *= a[4] = a[4]; 
b[3] = b[3] * temp = a[0] * a[1] * a[2] * a[4];
第二步
temp *= a[3] = a[4] * a[3];
b[2] = b[2] * temp = a[0] * a[1] * a[4] * a[3];
第三步
temp *= a[2] = a[4] * a[3] * a[2]; 
b[1] = b[1] * temp = a[0] * a[4] * a[3] * a[2];
第四步
temp *= a[1] = a[4] * a[3] * a[2] * a[1]; 
b[0] = b[0] * temp = a[4] * a[3] * a[2] * a[1];
由此可以看出从b[4]到b[0]均已经得到正确计算。
*/

//version 1(3 ms)
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int len = A.size();
        vector<int> B(len,1);
        int temp=1;
        for(int i=1;i<len;i++){
            B[i] = B[i-1] * A[i-1];
        }
        for(int i=len-1;i>=1;i--){
            temp *= A[i];
            B[i-1] *= temp;
        }
        return B;
    }
};