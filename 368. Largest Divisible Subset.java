/*
	方法一：采用DP，同时用一个path来记录，由于最后的最大值不一定在最后一位，需要一次loop来找到最大值的点，然后通过path将结果加到res。
*/

//version 1()
class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        List<Integer> res = new ArrayList<>();
        if (nums.length == 0) return res;
        Arrays.sort(nums);
        int[] D = new int[nums.length];
        int[] path = new int[nums.length];
        D[0] = 1;
        for (int i=1; i<nums.length; i++) {
            D[i] = 1;
            path[i] = i;
            for (int j=0; j<i; j++) {
                if (nums[i] % nums[j] == 0) {
                    D[i] = Math.max(D[i], D[j] + 1);
                    if (D[i] == D[j] + 1) {
                        path[i] = j;
                    }
                }
            }
        }
        
        int max = 0;
        for (int i=0; i<nums.length; i++) {
            if (D[i] > D[max]) {
                max = i;
            }
        }        
        int n = D[max];
        for (int i=0; i<n; i++) {            
            res.add(nums[max]);
            max = path[max];
        }
        return res;
    }
}