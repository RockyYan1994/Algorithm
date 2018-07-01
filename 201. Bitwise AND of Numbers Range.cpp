/*
	不太懂这个题的意思，大概就是左边有多少位是相同？
*/

//version 1(40 ms)
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int count = 0;
        while(m!=n){
            count++;
            m >>= 1;
            n >>= 1;
        }
        return m<<count;
    }
};