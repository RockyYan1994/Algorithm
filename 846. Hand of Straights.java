/*

*/

//version 1(59 ms)
class Solution {
    public boolean isNStraightHand(int[] hand, int W) {
        int n = hand.length;
        if (n % W != 0) return false;
        Map<Integer, Integer> map = new TreeMap<>();
        for (int num : hand) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        for (int num : map.keySet()) {
            int f = map.get(num);
            if (f <= 0) continue;
            for (int i = num; i < num + W; i++) {
                if (map.getOrDefault(i, 0) < f) return false;
                map.put(i, map.get(i) - f);
            }
        }
        return true;
    }
}