/*
	方法一：通过构造sums，每次通过sums[r2][c2]+sums[r1-1][c1-1]-sums[r2][c1-1]-sums[r1-1][c2]来计算。可以通过多加一行和一列来避免判断
*/

//version 1(12 ms)
class NumMatrix {
    vector<vector<int>> sums;
    int m,n;
public:
    NumMatrix(vector<vector<int>> matrix) {
        m = matrix.size();
        if (m == 0) return;
        n = matrix[0].size();
        if (n == 0) return;
        sums = vector<vector<int>>(m, vector<int>(n, 0));
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                sums[i][j] = matrix[i][j];
                if (i>0) sums[i][j] += sums[i-1][j];
                if (j>0) sums[i][j] += sums[i][j-1];
                if (i>0 && j>0) sums[i][j] -= sums[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (m == 0 || n == 0) return 0;
        int res = sums[row2][col2];
        if (row1 > 0) res -= sums[row1-1][col2];
        if (col1 > 0) res -= sums[row2][col1-1];
        if (row1>0 && col1>0) res += sums[row1-1][col1-1];
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */

//version 2()
class NumMatrix {
    vector<vector<int>> sums;
    int m,n;
public:
    NumMatrix(vector<vector<int>> matrix) {
        m = matrix.size();
        if (m == 0) return;
        n = matrix[0].size();
        if (n == 0) return;
        sums = vector<vector<int>>(m+1, vector<int>(n+1, 0));
        for (int i=1; i<m+1; i++) {
            for (int j=1; j<n+1; j++) {
                sums[i][j] = matrix[i-1][j-1] + sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (m == 0 || n == 0) return 0;
        int res = sums[row2+1][col2+1] - sums[row1][col2+1] - sums[row2+1][col1] + sums[row1][col1];
        return res;
    }
};