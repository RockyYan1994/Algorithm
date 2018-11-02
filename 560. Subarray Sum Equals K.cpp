/*
	方法一：采用sums实现，
	方法二：采用hashmap实现，只用遍历一次，并且空间复杂度也是n。主要思路就是记录到达某一个sum的cnt。
*/

//version 1(329 ms)
class Solution {
    public int subarraySum(int[] nums, int k) {
        if (nums.length == 0) return 0;
        int n = nums.length;
        int[] sums = new int[n+1];        
        for (int i=1; i<=n; i++) {
            sums[i] = sums[i-1] + nums[i-1];
        } 
        int cnt = 0;
        for (int i=1; i<=n; i++) {
            for (int j=0; j<i; j++) {
                if (sums[i] - sums[j] == k) cnt++;
            }
        }
        return cnt;
    }
}

//version 2(22 ms)
class Solution {
    public int subarraySum(int[] nums, int k) {
        if (nums.length == 0) return 0;
        Map<Integer, Integer> val2cnt = new HashMap<>();
        int cnt = 0, sum = 0;
        val2cnt.put(0, 1);
        for (int i=0; i<nums.length; i++) {
            sum += nums[i];
            if (val2cnt.containsKey(sum-k)) {
                cnt += val2cnt.get(sum-k);                
            }
            val2cnt.put(sum, val2cnt.getOrDefault(sum, 0)+1);
        }
        return cnt;
    }
}