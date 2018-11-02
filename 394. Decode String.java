/*

*/

//version 1(2 ms)
class Solution {
    public String decodeString(String s) {
        Stack<Integer> nums = new Stack<>();
        Stack<String> strs = new Stack<>();
        int i=0;
        String res = new String();
        while (i < s.length()) {
            if (Character.isDigit(s.charAt(i))) {
                int num = 0;
                while (i<s.length() && Character.isDigit(s.charAt(i))) {
                    num = num*10 + (s.charAt(i)-'0');
                    i++;
                }
                nums.push(num);
            } else if (s.charAt(i) == '[') {
                strs.push(res);
                res = "";
                i++;
            } else if (s.charAt(i) == ']') {
                StringBuilder sb = new StringBuilder();
                int num = nums.pop();
                while (num-- > 0) {
                    sb.append(res);
                }
                res = strs.pop() + sb.toString();
                i++;
            } else {
                res += s.charAt(i);
                i++;
            }            
        }
        return res;
    }
}