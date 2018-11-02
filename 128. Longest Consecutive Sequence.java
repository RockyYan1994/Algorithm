/*

*/


//version 1(2 ms)
class Solution {
    public int longestConsecutive(int[] nums) {
        if (nums.length == 0) return 0;
        Arrays.sort(nums);
        int res = 1, temp = 1;
        for (int i=1; i<nums.length; i++) {
            if (nums[i] == nums[i-1] + 1) {
                temp++;
                res = Math.max(res, temp);
            } else if (nums[i] == nums[i-1]) {
                continue;
            } else {
                temp = 1;
            }
        }
        return res;
    }
}

//version 2(10 ms)
class Solution {
    public int longestConsecutive(int[] nums) {
        if (nums.length == 0) return 0;
        int res = 0;
        Map<Integer, Integer> map = new HashMap<>();
        for (int num : nums) {
            if (map.containsKey(num)) continue;
            int left = map.getOrDefault(num-1, 0);
            int right = map.getOrDefault(num+1, 0);
            int sum = left + right + 1;
            res = Math.max(res, sum);
            map.put(num, 1);
            map.put(num-left, sum);
            map.put(num+right, sum);
        }
        return res;
    }
}

//version 3(7 ms)
class Solution {
    public int longestConsecutive(int[] nums) {
        if (nums.length == 0) return 0;
        int res = 0;
        Set<Integer> s = new HashSet<Integer>();
        for (int num : nums) s.add(num);
        for (int num : nums) {            
            if (!s.contains(num-1)) {
                int cnt = 1;
                while (s.contains(num+1)) {
                    num++;
                    cnt++;
                }
                res = Math.max(res, cnt);
            }
        }
        return res;
    }
}