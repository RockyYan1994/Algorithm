/*

*/

//version 1(TLE)
class Solution {
    public boolean validPalindrome(String s) {
        StringBuilder sb = new StringBuilder(s);
        if (isValid(sb)) return true;
        for (int i = 0; i < s.length(); i++) {
            char temp = sb.charAt(i);
            sb.deleteCharAt(i);
            if (isValid(sb)) return true;
            sb.insert(i, temp);
        }
        return false;
    }
    
    private boolean isValid(StringBuilder sb) {
        int l = 0, r = sb.length()-1;
        while (l < r) {
            if (sb.charAt(l) != sb.charAt(r)) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
}

//version 2(19 ms)
class Solution {
    public boolean validPalindrome(String s) {
        int l = 0, r = s.length() - 1;
        while (l < r) {
            if (s.charAt(l) != s.charAt(r)) {
                return isValid(s, l + 1, r) || isValid(s, l, r - 1);                
            }
            l++;
            r--;
        }        
        return true;
    }
    
    private boolean isValid(String s, int l, int r) {
        while (l < r) {
            if (s.charAt(l) != s.charAt(r)) return false;
            l++;
            r--;
        }
        return true;
    }
}