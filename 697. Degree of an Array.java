/*

*/

//version 1(21 ms)
class Solution {
    public int findShortestSubArray(int[] nums) {
        Map<Integer, int[]> M = new HashMap<>();
        int maxDegree = 0, res = nums.length;
        for (int i = 0; i < nums.length; i++) {
            if (!M.containsKey(nums[i])) {
                M.put(nums[i], new int[]{0, i, i});
            }
            int[] info = M.get(nums[i]);
            info[0]++;
            info[2] = i;
            M.put(nums[i], info);
            maxDegree = Math.max(maxDegree, info[0]);
        }
        for (Map.Entry<Integer, int[]> pair : M.entrySet()) {
            int[] info = pair.getValue();
            if (info[0] == maxDegree) {
                res = Math.min(res, info[2] - info[1] + 1);
            }
        }
        return res;
    }
}