/*
	方法一：和fruit那个问题一样，只是换了一下描述，注意second一定要先于first判断，因为初始化的时候可能会遇到first和second都不相同的情况。
*/

//version 1(4 ms)
class Solution {
    public int lengthOfLongestSubstringTwoDistinct(String s) {
        int first = 0, second = 0, secondCount = 0, count = 0, res = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) - 'a' == second) {
                count++;
                secondCount++;
            } else if (s.charAt(i) - 'a' == first) {
                count++;
                secondCount = 1;
                first = second;
                second = s.charAt(i) - 'a';
            } else {
                first = second;
                second = s.charAt(i) - 'a';
                count = secondCount + 1;
                secondCount = 1;                
            }
            res = Math.max(count, res);
        }
        return res;
    }
}

//version 2(11 ms)
class Solution {
    public int lengthOfLongestSubstringTwoDistinct(String s) {
        Map<Integer, Integer> M = new HashMap<>();
        int res = 0, left = 0;
        for (int i = 0; i < s.length(); i++) {
            int c = s.charAt(i) - 'a';
            M.put(c, i);
            if (M.size() > 2) {
                int minPos = s.length();
                for (Map.Entry<Integer, Integer> pair : M.entrySet()) {
                    minPos = Math.min(minPos, pair.getValue());                    
                }
                M.remove(s.charAt(minPos) - 'a');
                left = minPos + 1;
            }
            res = Math.max(res, i - left + 1);
        }
        return res;
    }
}