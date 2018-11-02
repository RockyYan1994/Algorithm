/*
	方法一：通过验证如果有超过一个1.
	方法二：
*/

//version 1() 
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (!n) return false;
        bool res = false;
        while (n) {
            bool ans = n & 1;
            if (ans) {
                if (res) return false;
                else res = true;
            }
            n >>= 1;
        }
        return true;
    }
};

//version 2()
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};