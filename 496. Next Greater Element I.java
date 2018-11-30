/*

*/

//version 1()
class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int[] res = new int[nums1.length];
        Map<Integer, Integer> M = new HashMap<>();
        Stack<Integer> S = new Stack<Integer>();
        for (int i = 0; i < nums2.length; i++) {
            while (!S.isEmpty() && S.peek() < nums2[i]) {
                M.put(S.pop(), nums2[i]);
            }
            S.push(nums2[i]);
        }
        for (int i = 0; i < nums1.length; i++) {
            res[i] = M.getOrDefault(nums1[i], -1);
        }
        return res;
    }
}