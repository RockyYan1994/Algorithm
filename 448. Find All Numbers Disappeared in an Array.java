/*
    方法一：采用一个数组来记录，空间为o(n)
    方法二：优化空间
*/

//version 1(9 ms)
class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        int[] has = new int[nums.length];
        Arrays.fill(has, 0);
        List<Integer> res = new ArrayList<>();
        for (int num : nums) {
            has[num-1] = 1;
        }
        for (int i=0; i<has.length; i++) {
            if (has[i] == 0) {
                res.add(i+1);
            }
        }
        return res;
    }
}

//version 2(7 ms)
class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {                 
        int n = nums.length;
        List<Integer> res = new ArrayList<>();
        for (int i=0; i<n; i++) {
            nums[(nums[i]-1)%n] += n;
        }
        for (int i=0; i<n; i++) {
            if (nums[i]-1 < n) res.add(i+1);
        }
        return res;
    }
}