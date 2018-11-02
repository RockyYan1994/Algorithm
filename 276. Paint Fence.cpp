/*
	方法一：采用DP的方法实现。
	方法二：优化成O(1)的空间
*/

//version 1(0 ms)
class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0 || k == 0) return 0;
        if (n == 1) return k;
        int res = 0;
        vector<int> same(n, 0);
        vector<int> diff(n, 0);
        
        same[0] = same[1] = k;
        diff[0] = k;
        diff[1] = k * (k-1);
        for (int i=2; i<n; i++) {
            same[i] = diff[i-1];
            diff[i] = (k-1) * same[i-1] + (k-1) * diff[i-1];
        }
        return diff[n-1] + same[n-1];
    }
};

//version 2
class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0 || k == 0) return 0;
        if (n == 1) return k;
        int res = 0;
        int same = k, diff = k*(k-1);
        for (int i=2; i<n; i++) {
            int last_same = same;
            same = diff;
            diff = (k-1) * diff + (k-1) * last_same;
        }
        return same + diff;
    }
};