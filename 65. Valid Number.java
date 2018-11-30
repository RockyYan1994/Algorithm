/*

*/

//version 1()
class Solution {
    public boolean isNumber(String s) {        
        s = s.trim();        
        // s1 is the original state, s2 is after point occur, s3 is after 'e' occur, s4 is can a "+/-"
        // occured, s5 is need number occur.
        final int s0 = 0, s1 = 1, s2 = 2, s3 = 3, s4 = 4, s5 = 5, s6 = 6;
        boolean hasNum = false;
        int state = s0;
        for (int i = 0; i < s.length(); i++) {            
            if (s.charAt(i) >= '0' && s.charAt(i) <= '9') {
                hasNum = true;
                if (state == s0) {
                    state = s1;
                } else if (state == s2) {
                    state = s3;
                } else if (state == s4 || state == s5) {
                    state = s6;
                }
            } else if (s.charAt(i) == '.') {                
                if (state != s1 && state != s0) {
                    return false;
                }                
                state = s2;                
            } else if (s.charAt(i) == 'e') {                
                if (!hasNum || (state != s1 && state != s3 && state != s2)) {
                    return false;
                }
                state = s4;
            } else if (s.charAt(i) == '+' || s.charAt(i) == '-') {
                if (state != s0 && state != s4) {
                    return false;
                }
                state = state == s0 ? s1 : s5;
            } else {
                return false;
            }            
        }        
        System.out.println(state);
        return hasNum && (state == s1 || state == s3 || state == s6 || state == s2);
    }
}