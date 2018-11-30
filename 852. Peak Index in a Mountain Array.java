/*

*/

//version 1(2 ms)
class Solution {
    public int peakIndexInMountainArray(int[] A) {
        for (int i = 0; i < A.length - 1; i++) {
            if (A[i] > A[i + 1]) {
                return i;
            }
        }
        return -1;
    }
}

//version 2(1 ms)
class Solution {
    public int peakIndexInMountainArray(int[] A) {
        int l = 0, r = A.length - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (A[mid] < A[mid + 1]) {
                l = mid;
            } else if (A[mid - 1] > A[mid]) {
                r = mid;
            } else {
                return mid;
            }
        }
        return -1;
    }
}