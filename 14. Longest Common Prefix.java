/*

*/

//version 1(9 ms)
class Solution {
    public String longestCommonPrefix(String[] strs) {
        StringBuilder res = new StringBuilder();
        if (strs.length == 0) return res.toString();
        int pos=0;
        while (pos < strs[0].length()) {
            char ch = strs[0].charAt(pos);
            for (int i=0; i<strs.length; i++) {
                if (strs[i].length() <= pos) {
                    return res.toString();
                }
                if (strs[i].charAt(pos) != ch) {
                    return res.toString();
                }
            }
            res.append(ch);
            pos++;
        }
        return res.toString();
    }
}