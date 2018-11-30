/*

*/

//version 1(TLE)
class Solution {
    public int countBinarySubstrings(String s) {
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            int cnt = 0, turn = 0;
            for (int j = i; j < s.length(); j++) {
                cnt += s.charAt(j) == '1' ? 1 : -1;
                if (i != j && s.charAt(j - 1) != s.charAt(j)) {
                    turn++;
                }
                if (turn > 1) break;
                if (cnt == 0) res++;
            }
        }
        return res;
    }
}

//version 2(18 ms)
class Solution {
    public int countBinarySubstrings(String s) {
        int res = 0, lastCnt = 0, now = -1, nowCnt = 0;
        for (int i = 0; i < s.length(); i++) {
            int cur = s.charAt(i) - '0';
            if (cur == now) {
                nowCnt++;                
            } 
            if (cur != now ){
                //System.out.println(now);
                now = cur;                
                res += Math.min(lastCnt, nowCnt);
                //System.out.println(lastCnt + ", " + nowCnt);
                lastCnt = nowCnt;
                nowCnt = 1;
            }
        }        
        res += Math.min(lastCnt, nowCnt);
        return res;
    }
}