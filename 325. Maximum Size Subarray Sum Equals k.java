/*

*/

//version 1(1000 ms)
class Solution {
    public int maxSubArrayLen(int[] nums, int k) {
        int[] prefix = new int[nums.length + 1];        
        for (int i = 1; i <= nums.length; i++) {
            prefix[i] = prefix[i-1] + nums[i-1];
        }
        int max = 0;
        for (int i = 0; i <= nums.length; i++) {
            for (int j = i + 1; j <= nums.length; j++) {
                if (prefix[j] - prefix[i] == k) {
                    System.out.println(j + ", " + i);
                    max = Math.max(j - i, max);
                }
            }
        }
        return max;
    }
}

//version 2(14 ms)
class Solution {
    public int maxSubArrayLen(int[] nums, int k) {
        Map<Integer, Integer> M = new HashMap();
        int sum  = 0, res = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            if (sum == k) res = Math.max(res, i + 1);
            else if (M.containsKey(sum - k)) res = Math.max(res, i - M.get(sum - k));
            if (!M.containsKey(sum)) M.put(sum, i);
        }
        return res;
    }
}