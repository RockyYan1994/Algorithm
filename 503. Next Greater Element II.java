/*

*/

//version 1(64 ms)
class Solution {
    public int[] nextGreaterElements(int[] nums) {        
        Map<Integer, Integer> M = new HashMap<>();
        int n = nums.length;
        int[] res = new int[nums.length];
        Stack<Integer> S = new Stack<>();
        for (int i = 0; i < n * 2 - 1; i++) {
            while (!S.isEmpty() && nums[i % n] > nums[S.peek() % n]) {
                M.put(S.pop(), nums[i % n]);
            }
            S.push(i);
        }
        for (int i = 0; i < nums.length; i++) {
            if (M.containsKey(i)) {
                res[i] = M.get(i);
            } else if (M.containsKey(i + n)) {
                res[i] = M.get(i + n);
            } else {
                res[i] = -1;
            }
        }
        return res;
    }
}

//version 2(35 ms)
class Solution {
    public int[] nextGreaterElements(int[] nums) {        
        int n = nums.length;
        int[] res = new int[nums.length];
        Stack<Integer> S = new Stack<>();
        Arrays.fill(res, -1);
        for (int i = 0; i < 2 * n; i++) {            
            while (!S.isEmpty() && nums[i % n] > nums[S.peek()]) {                
                res[S.pop()] = nums[i % n];
            }
            if (i < n) S.push(i);
        }
        return res;
    }
}