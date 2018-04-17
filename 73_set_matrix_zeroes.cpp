/*
	first
    查看了要求以后，发现需求是使用in place来实现操作，因此想到利用第一行和第一列来作为mark，首先判断第一行和第一列是否为0并且用两个变量来保存结果。
    然后遍历数组，如果有某一个元素为0，那个就设置该元素所在列的第一行为0和该元素所在行的第一列为0，最后就是设置0的操作。
    查看了discussion之后发现思路是一样的，但是可以有优化的地方，可以把第一行和第一列的判断集成在大的循环里面，
*/

//version 1(55 ms)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty()) return;
        int first_row=1,first_col = 1;
        
        for(int i=0;i<matrix.size();i++){
            if(matrix[i][0]==0) {
                first_col = 0;
                break;
            }
        }
        for(int i=0;i<matrix[0].size();i++){
            if(matrix[0][i]==0) {
                first_row=0;
                break;
            }
        }
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][0]==0||matrix[0][j]==0) matrix[i][j]=0;
            }
        }
        if(first_col==0){
            for(int i=0;i<matrix.size();i++) matrix[i][0] = 0;
        }
        if(first_row==0){
            for(int i=0;i<matrix[0].size();i++) matrix[0][i] = 0;
        }
        return;
    }
};