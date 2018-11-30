/*

*/

//version 1(100 ms)
class Solution {
    public boolean canCross(int[] stones) {        
        int n = stones.length;
        Map<Integer, List<Integer>> M = new HashMap<>();
        for (int pos : stones) {
            M.put(pos, new ArrayList<>());
        }        
        M.get(0).add(0);
        for (int key : stones) {
            List<Integer> L = M.get(key);
            for (int val : L) {
                for (int k = val - 1; k <= val + 1; k++) {
                    int target = key + k;
                    if (k <= 0 || target > stones[n-1]) continue;
                    if (target == stones[n-1]) return true;
                    if (M.containsKey(target)) {
                        M.get(target).add(k);
                    }
                }
            }
        }
        return false;
    }
}