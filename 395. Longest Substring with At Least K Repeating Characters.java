/*

*/

//version 1(58 ms)
class Solution {
    public int longestSubstring(String s, int k) {        
        return helper(s.toCharArray(), k, 0, s.length()-1);
    }

    private int helper(char[] C, int k, int l, int r) {
        if (l > r) return 0;
        int[] A = new int[26];
        for (int i = l; i <= r; i++) {
            A[C[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (A[i] < k && A[i] > 0) {
                for (int j = l; j <= r; j++) {
                    if (C[j] - 'a' == i)
                        return Math.max(helper(C, k, l, j-1), helper(C, k, j+1, r));
                }
            }
        }
        return r - l + 1;
    }
}