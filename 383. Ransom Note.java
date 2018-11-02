/*

*/

//version 1(9 ms)
class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int[] cnt = new int[26];
        for (char ch : magazine.toCharArray()) {
            cnt[ch - 'a']++;
        }
        for (char ch : ransomNote.toCharArray()) {
            if (--cnt[ch - 'a'] < 0) return false;
        }
        return true;
    }
}