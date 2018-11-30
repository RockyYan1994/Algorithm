/*

*/

//version 1()
class Solution {
    
    private int[] nums;
    
    private Random random;

    public Solution(int[] nums) {
        this.nums = nums;
        random = new Random();
    }
    
    public int pick(int target) {
        int res = -1, total = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == target) {
                int x = random.nextInt(++total);
                res = x == 0 ? i : res;
            }
        }
        return res;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */