/*

*/

//version 1()
class Solution {
    public List<int[]> getSkyline(int[][] buildings) {
        TreeSet<int[]> vertices = new TreeSet<>((a,b) -> {
            if (a[0] != b[0]) {
                return a[0] - b[0];
            } else if (a[2] != b[2]) {
                return b[2] - a[2];
            } else if (a[2] == 0) {
                return a[1] - b[1];
            } else {
                return b[1] - a[1];
            }
        });        
        PriorityQueue<Integer> Q = new PriorityQueue<>((a, b) -> (b - a));
        List<int[]> res = new ArrayList<>();
        for (int[] building : buildings) {
            // add the begin point of building
            vertices.add(new int[]{building[0], building[2], 1});
            // add the end point of building
            vertices.add(new int[]{building[1], building[2], 0});
        }                
        
        int top = 0;
        Q.add(0);
        for (int[] vertice : vertices) {
            //System.out.println(vertice[0] + ", " + vertice[1] + ", " + vertice[2]);
            if (vertice[2] == 1) {
                Q.add(vertice[1]);
            } else {
                Q.remove(vertice[1]);
            }
            int cur = Q.peek();
            if (cur != top) {
                res.add(new int[]{vertice[0], cur});
                top = cur;
            }
        }
        return res;
    }
}