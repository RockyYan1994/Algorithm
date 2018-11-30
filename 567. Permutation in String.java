/*

*/

//version 1()
class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int m = s1.length(), n = s2.length();
        if (m > n) return false;
        int[] A = new int[26];
        for (int i=0; i<m; i++) {
            A[s1.charAt(i) - 'a']++;
        }
        
        int cnt = m;
        for (int i=0; i<n; i++) {
            int pos = s2.charAt(i) - 'a';
            
            if (i >= m) {
                A[s2.charAt(i-m) - 'a']++;
                if (A[s2.charAt(i-m) - 'a'] > 0) {                    
                    cnt++;
                }                    
            }            
            cnt -= A[pos] > 0 ? 1 : 0;
            A[pos]--;            
            if (cnt == 0) return true;
        }
        return false;
    }
}