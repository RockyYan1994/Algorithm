/*

*/

//version 1(8 ms)
class Solution {
    public String countAndSay(int n) {
        if (n == 0) return "0";
        String s = "1";
        for (int i=2; i<=n; i++) {
            s = countAndSay(s);
        }
        return s;
    }
    
    private String countAndSay(String s) {
        int i = 0;
        StringBuilder res = new StringBuilder();
        while (i < s.length()) {
            int cnt = 1; 
            int num = s.charAt(i) - '0';
            while (i+1 < s.length() && s.charAt(i) == s.charAt(i+1)) {
                cnt++;
                i++;
            }
            res.append(cnt + "" + num);
            i++;
        }
        return res.toString();
    }
}