/*

*/

//version 1(5 ms)
class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> L = new ArrayList<>();
        for (int num : nums) {
            int val = num < 0 ? -num : num;
            if (nums[val-1] < 0) {
                L.add(val);
            } else {
                nums[val-1] = -nums[val-1];
            }            
        }
        return L;
    }
}