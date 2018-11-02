/*
    方法一：采用DP，分别用c2, c3, c5来记录当前2，3，5移动的位置，每次选最小的数。注意一个问题，就是在mul2，mul3， mul5结果相同的时候，需要同时更新。
*/

//version 1(4 ms)
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 0) return 0;
        // store 2, 3, 5 ptr seperately
        int c2=0, c3=0, c5=0;
        vector<int> vec(n, 1);
        for (int i=1; i<n; i++) {
            int mul2 = vec[c2] * 2;
            int mul3 = vec[c3] * 3;
            int mul5 = vec[c5] * 5;
            vec[i] = min(mul2, min(mul3, mul5));
            if (vec[i] == mul2) c2++;
            if (vec[i] == mul3) c3++;
            if (vec[i] == mul5) c5++;
        }
        return vec[n-1];
    }
};