/*
	方法一：采用DP，通过记录[i，j-1]的count，
	方法二：空间优化，并且剪枝。
*/

//version 1(928 ms)
class Solution {
    public int longestValidParentheses(String s) {
        int n = s.length(), res = 0;        
        for (int i = 0; i < n; i++) {
            int[] D = new int[n];
            for (int j = i; j < n; j++) {                
                if (i == j) {
                    D[j] = s.charAt(i) == '(' ? 1 : -1;
                    continue;
                }
                if (D[j - 1] < 0) {
                    D[j] = -1;
                    continue;
                }
                
                D[j] = s.charAt(j) == '(' ? D[j-1] + 1 : D[j-1] - 1;
                if (D[j] == 0) res = Math.max(res, j - i + 1);
            }
        }
        return res;
    }
}

//version 2(256 ms)
class Solution {
    public int longestValidParentheses(String s) {
        int n = s.length(), res = 0;        
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == ')') continue;
            int cnt = 0;
            for (int j = i; j < n; j++) {                
                if (i == j) {
                    cnt = s.charAt(i) == '(' ? 1 : -1;
                    continue;
                }
                if (cnt < 0) {                    
                    break;
                }
                
                cnt = s.charAt(j) == '(' ? cnt + 1 : cnt - 1;
                if (cnt == 0) res = Math.max(res, j - i + 1);
            }
        }
        return res;
    }
}

//version 3(10 ms)
class Solution {
    public int longestValidParentheses(String s) {
        int n = s.length(), res = 0;        
        int[] D = new int[n+1];
        for (int i = 1; i <= n; i++) {
            if (s.charAt(i-1) == '(') continue;
            if (i >= 2 && s.charAt(i-1) == '(') {                
                D[i] = D[i-2] + 2;
                //System.out.println(D[i]);
            }
            if (i - D[i-1] >= 2 && s.charAt(i - D[i-1] - 2) == '(') {
                D[i] = D[i - D[i-1] - 2] + D[i-1] + 2;
            }
            res = Math.max(res, D[i]);
            //System.out.println(i + ", " + D[i]);
        }
        return res;
    }
}

//version 4(15 ms)
class Solution {
    public int longestValidParentheses(String s) {
        int n = s.length(), res = 0;        
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                stack.push(i);
            } else {
                if (stack.isEmpty() || s.charAt(stack.peek()) == ')') {
                    stack.push(i);
                } else {
                    stack.pop();
                    if (stack.isEmpty()) {
                        res = Math.max(res, i + 1);
                    } else {
                        res = Math.max(res, i - stack.peek());   
                    }
                }
            }
        }
        return res;
    }
}

//version 5(9 ms)
class Solution {
    public int longestValidParentheses(String s) {
        int n = s.length(), res = 0, cnt = 0, len = 0;
        
        for (int i = 0; i < n; i++) {
            cnt += s.charAt(i) == '(' ? 1 : -1;
            len++;
            if (cnt == 0) {
                res = Math.max(res, len);
            } else if (cnt < 0) {
                cnt = 0;
                len = 0;
            }
        }
        
        cnt = 0; len = 0;
        
        for (int i = n-1; i >=0 ; i--) {
            cnt += s.charAt(i) == ')' ? 1 : -1;
            len++;
            if (cnt == 0) {
                res = Math.max(res, len);
            } else if (cnt < 0) {
                cnt = 0;
                len = 0;
            }
        }
        
        return res;
    }
}