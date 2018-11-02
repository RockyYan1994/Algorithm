/*
	方法一：采用每次取两个值异或的方法
	方法二：采用每次减去最后一个为1的位。
*/

//version 1()
class Solution {
public:
    int hammingDistance(int x, int y) {
        int cnt = 0;
        while (x!=0 || y!=0) {
            cnt += (x&1)^(y&1);
            x >>= 1;
            y >>= 1;            
        }
        return cnt; 
    }
};

//version 2()
class Solution {
public:
    int hammingDistance(int x, int y) {
        int cnt = 0, n = x^y;
        while (n) {
            cnt++;
            n &= n-1;
        }
        return cnt; 
    }
};