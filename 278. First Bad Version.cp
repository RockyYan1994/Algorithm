/*

*/

//version 1(0 ms)
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (n == 0) return 0;
        int l = 0, r = n-1;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (isBadVersion(mid)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};