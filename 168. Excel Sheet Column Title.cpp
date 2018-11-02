/*

*/

//version 1(0 ms)
class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while(n) {
            int temp = --n%26;
            res += (char) (temp + 'A');
            n = n / 26;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

//version 2(from xcv58)
return n == 0 ? "" : convertToTitle((n - 1) / 26) + (char) ((n - 1) % 26 + 'A');