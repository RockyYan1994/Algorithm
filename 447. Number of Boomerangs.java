/*

*/

//version 1(145 ms)
class Solution {
    public int numberOfBoomerangs(int[][] points) {
        int res = 0;
        if (points == null || points.length == 0 || points[0].length == 0) return res;
        for (int i=0; i<points.length; i++) {
            Map<Integer, Integer> M = new HashMap<>();
            for (int j = 0; j<points.length; j++) {
                if (i != j) {
                    int d = getDistance(points[i][0], points[j][0], points[i][1], points[j][1]);
                    M.put(d, M.getOrDefault(d, 0) + 1);
                }
            }
            for (int val : M.values()) {
                res += val * (val-1);
            }
        }
        return res;
    }
    
    private int getDistance(int x1, int x2, int y1, int y2) {
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    }
}