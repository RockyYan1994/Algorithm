/*

*/

//version 1(2 ms)
class Solution {
    public int[] numberOfLines(int[] widths, String S) {
        if (S.isEmpty()) return new int[] {0, 0};
        int line = 1;
        int cnt = 0;
        for (int i=0;i<S.length(); i++) {
            int index = S.charAt(i) - 'a';
            int len = widths[index];
            if (len + cnt > 100) {
                line++;
                cnt = 0;
            }
            cnt += len;
        }
        return new int[] {line, cnt};
    }
}