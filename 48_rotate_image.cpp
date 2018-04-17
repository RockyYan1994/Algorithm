/*
	first
	通过观察，发现可以通过一次水平翻转和一次对角翻转来实现顺时针转动90度。
	在考虑对角交换的时候出现了几次错误，对角堆成的条件主要是将左上部分的元素和右下交换，因此条件应该是两个指针之和小于n。
*/

//version 1(4 ms)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //ratate row
        for(int i=0;i<n;i++){
            int j=0,k=n-1;
            while(j<k){
                swap(matrix[i][j++],matrix[i][k--]);
            }
        }
        //rotate diagonal
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i+j>=n) continue;
                swap(matrix[i][j],matrix[n-1-j][n-1-i]);
            }
        }
    }
};