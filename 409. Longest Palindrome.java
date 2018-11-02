/*

*/

//version 1(11 ms)
class Solution {
    public int longestPalindrome(String s) {
        Map<Character, Integer> map = new HashMap<Character, Integer>();
        for (char ch : s.toCharArray()) {
            map.put(ch, map.getOrDefault(ch, 0) + 1);            
        }
        boolean single = false;
        int res = 0;
        for (Map.Entry<Character, Integer> pair : map.entrySet()) {
            if (pair.getValue() >= 2) {
                res += pair.getValue() % 2 == 0 ? pair.getValue() : pair.getValue() - 1;
            }
            if (pair.getValue() % 2 == 1) {
                single = true;
            }
        }
        return single ? res + 1 : res;
    }
}