/*

*/
//version 1(1 ms)
class Solution {
    public int countComponents(int n, int[][] edges) {
        if (edges == null || edges.length == 0 || edges[0].length == 0) return n;
        int[] A = new int[n];
        for (int i = 0; i < n; i++) {
            A[i] = i;
        }
        int res = n;
        for (int[] edge : edges) {
            int a = find(A, edge[0]);
            int b = find(A, edge[1]);
            if (a != b) {
                 res--;
                A[a] = b;
            }
        }
        return res;
    }
    
    private int find(int[] A, int i) {
        if (i != A[i]) {
            A[i] = find(A, A[i]);
        }
        return A[i];
    }
}