/*

*/

//version 1(8 ms)
class Solution {
    
    public int calculate(String s) {
        if (s.isEmpty()) return 0;
        return helper(s, 0)[0];
    }
    
    private int[] helper(String s, int start) {
        Stack<Integer> stack = new Stack<>();
        stack.push(0);
        int num = 0, end = s.length();
        char sign = '+';
        for (int i = start; i <= s.length(); i++) {
            if (i < s.length() && s.charAt(i) == ' ') continue;
            if (i < s.length() && Character.isDigit(s.charAt(i))) {
                num = num * 10 + (s.charAt(i) - '0');
                continue;
            }
            if (i < s.length() && s.charAt(i) == '(') {
                int[] rets = helper(s, i + 1);
                i = rets[1];
                num = rets[0];                
                continue;
            }            
            if (sign == '+' || sign == '-') {
                stack.push(num * (sign == '-' ? -1 : 1));
                num = 0;
            } else if (sign == '*') {
                stack.push(stack.pop() * num);
            } else if (sign == '/') {
                stack.push(stack.pop() / num);
            }
            num = 0;
            if (i < s.length() && s.charAt(i) == ')') {
                end = i;
                break;
            }
            if (i < s.length()) sign = s.charAt(i);
        }
        int res = 0;
        while (!stack.isEmpty()) {
            res += stack.pop();
        }
        return new int[]{res, end};
    }
}