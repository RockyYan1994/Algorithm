/*

*/

//version 1(Time limited)
class Solution {
public:
    bool canWinNim(int n) {
        if (n < 4) return true;
        vector<int> res(4, true);
        for (int i=3; i<=n; i++) {
            res[i%4] = !(res[(i-1)%4] && res[(i-2)%4] && res[(i-3)%4]);
        }
        return res[(n-1)%4];
    }
};

//version 2()
class Solution {
public:
    bool canWinNim(int n) {
        return n % 4;
    }
};