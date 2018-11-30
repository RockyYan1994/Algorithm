/*
	方法一：还是采用count计数的思路，如果遇到*，可以看成当前的范围 -1， 0 ，+1. 
*/

//version 1(3 ms)
class Solution {
    public boolean checkValidString(String s) {
        int l = 0, h = 0;
        for (char c : s.toCharArray()) {
            if (c == '(') {
                l++;
                h++;
            } else if (c == ')') {
                if (l > 0) l--;
                h--;
            } else {
                if (l > 0) l--;
                h++;
            }
            if (h < 0) return false;
        }
        return l == 0;
    }
}