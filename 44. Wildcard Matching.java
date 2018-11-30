/*
	注意方法二进行了空间优化，但是要注意为了避免D[0][0] 设置的影响，必须在之后把 D[next][0]设置为false。
*/

//version 1(38 ms)
class Solution {
    public boolean isMatch(String s, String p) {
        boolean[][] D = new boolean[s.length()+1][p.length()+1];
        D[0][0] = true;
        for (int i = 1; i < p.length() + 1; i++) {
            D[0][i] = D[0][i-1] & (p.charAt(i-1) == '*');
        }
        for (int i = 1; i <= s.length(); i++) {
            for (int j = 1; j <= p.length(); j++) {
                if (Character.isLetter(p.charAt(j - 1)) && p.charAt(j - 1) != s.charAt(i - 1)) {
                    D[i][j] = false;
                } else if (p.charAt(j - 1) == '?' || p.charAt(j - 1) == s.charAt(i - 1)) {
                    D[i][j] = D[i - 1][j - 1];
                } else {
                    D[i][j] = D[i - 1][j] | D[i][j - 1];
                }
            }            
        }
        return D[s.length()][p.length()];
    }
}

//version 2(37 ms)
class Solution {
    public boolean isMatch(String s, String p) {
        boolean[][] D = new boolean[2][p.length()+1];
        D[0][0] = true;
        for (int i = 1; i < p.length() + 1; i++) {
            D[0][i] = D[0][i-1] & (p.charAt(i-1) == '*');
        }
        int old = 0, next = 0;
        for (int i = 1; i <= s.length(); i++) {
            next = 1 - old;  
            D[next][0] = false; // this is very important.
            for (int j = 1; j <= p.length(); j++) {
                if (Character.isLetter(p.charAt(j - 1)) && p.charAt(j - 1) != s.charAt(i - 1)) {
                    D[next][j] = false;
                } else if (p.charAt(j - 1) == '?' || p.charAt(j - 1) == s.charAt(i - 1)) {
                    D[next][j] = D[old][j - 1];
                } else {
                    D[next][j] = D[old][j] | D[next][j - 1];
                }
            }
            old = next;
        }
        return D[next][p.length()];
    }
}