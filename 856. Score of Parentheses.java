/*

*/

//version 1(5 ms)
class Solution {
    public int scoreOfParentheses(String S) {
        Stack<Integer> stack = new Stack<>();
        for (char c : S.toCharArray()) {
            if (c == '(') {
                stack.push(-1);
            } else {
                if (stack.peek() == -1) {
                    stack.pop();
                    stack.push(1);
                } else {
                    int cur = 0;
                    while (stack.peek() != -1) {
                        cur += stack.pop();
                    }
                    stack.pop();
                    stack.push(cur * 2);
                }
            }
        }
        int res = 0;
        while (!stack.isEmpty()) {
            res += stack.pop();
        }
        return res;
    }
}