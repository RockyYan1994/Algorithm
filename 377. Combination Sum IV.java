/*

*/

//version 1()
class Solution {
    public int combinationSum4(int[] nums, int target) {
        int[] D = new int[target+1];
        D[0] = 1;
        for (int i=1; i<=target; i++) {
            D[i] = 0;
            for (int j = 0; j < nums.length; j++) {
                if (i - nums[j] >= 0) {
                    D[i] += D[i - nums[j]];
                }
            }
        }
        return D[target];
    }
}