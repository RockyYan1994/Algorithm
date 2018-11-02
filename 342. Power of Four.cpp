/*
	方法一：递归/4判断/
	方法二：观察power of 4的例子，发现可以是101010101010这样的格式。或者1.
*/

//version 1(4 ms)
class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num == 0) return false;
        if (num == 1) return true;
        if (num % 4 == 0) return isPowerOfFour(num/4);
        return false;
    }
};

class Solution {
public:
	bool isPowerOfFour(int num) {
		return num>0 && (num&(num-1)) == 0 && (0x55555555 & num) != 0;
	}
};