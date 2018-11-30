/*

*/

//version 1(84 ms)
class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        int m = matrix.length, n = matrix[0].length;
        PriorityQueue<int[]> Q = new PriorityQueue<>((a,b) -> a[0] - b[0]);
        for (int i=0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                Q.add(new int[]{matrix[i][j], i, j});
            }
        }
        while (k > 1) {
            Q.poll();
            k--;
        }
        return Q.poll()[0];
    }
}

//version 2(0 ms)
class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        int m = matrix.length, n = matrix[0].length;
        int l = matrix[0][0], r = matrix[m-1][n-1] + 1;
        while (l < r) {
            int cnt = 0, mid = l + (r - l) / 2, j = n-1;
            for (int i = 0; i < m; i++) {
                while (j >= 0 && matrix[i][j] > mid) j--;
                cnt += j + 1;
            }
            if (cnt < k) l = mid + 1;
            else r = mid;
        }
        return l;
    }
}