/*

*/

//version 1(156 ms)
class Solution {
    public int countSubstrings(String s) {
        int cnt = 0;
        for (int i=1; i<=s.length(); i++) {
            for (int j=0; j<i; j++) {
                if (isPalindrome(s.substring(j, i))) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
    
    private boolean isPalindrome(String s) {
        for (int i=0; i<=s.length()/2; i++) {
            if (s.charAt(i) != s.charAt(s.length()-i-1)) return false;
        }
        return true;
    }
}

//version 2(12 ms)
class Solution {
    public int countSubstrings(String s) {
        int cnt = 0, len = s.length()*2;
        for (int i=0; i<len; i++) {
            int l = i/2, r = l+i%2;
            while (l>=0 && r<s.length() && s.charAt(l) == s.charAt(r)) {
                cnt++;
                l--; r++;
            }
        }
        return cnt;
    }
}