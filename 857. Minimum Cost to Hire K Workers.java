/*

*/

//version 1(70 ms)
class Solution {
    public double mincostToHireWorkers(int[] quality, int[] wage, int K) {
        double[][] D = new double[quality.length][2];
        for (int i = 0; i < quality.length; i++) {
            D[i][0] = (double) wage[i] / quality[i];
            D[i][1] = quality[i];
        }
        Arrays.sort(D, (a, b) -> (Double.compare(a[0], b[0])));
        PriorityQueue<Double> pq = new PriorityQueue();
        double res = Double.MAX_VALUE, total = 0.0;        
        for (double[] worker : D) {
            total += worker[1];
            pq.add(-worker[1]);
            if (pq.size() > K) {
                total += pq.poll();
            }
            if (pq.size() == K) res = Math.min(res, total * worker[0]);
        }
        return res;
    }
}