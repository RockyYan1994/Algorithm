/*

*/

//version 1(3 ms)
class Solution {
    public int lengthLongestPath(String input) {
        int res = 0;
        Stack<Integer> prefix = new Stack<>();
        String[] S = input.split("\n");
        for (String s : S) {
            int t = s.lastIndexOf("\t") + 1;
            while (t < prefix.size()) prefix.pop();
            int pre = prefix.empty() ? 0 : prefix.peek();
            if (s.contains(".")) {
                res = Math.max(res, pre + s.length() - t);
            } else {
                prefix.push(pre + s.length() - t + 1);
            }
        }
        return res;
    }
}