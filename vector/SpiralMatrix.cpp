// first
// 首先想到使用每一圈的思想来输入，设定一个circle计量第几圈，row和col是行和列。当返回的vector和行列乘积相同则推出。

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if(matrix.size()==0) return ret;
        int row = matrix.size();
        int col = matrix[0].size();
        int circle = 0;
        int count = matrix.size()*matrix[0].size();
        while(true){
            if(ret.size()==count) break;
            for(int i=circle;i<col-circle;i++){
                ret.push_back(matrix[circle][i]);
            }
            if(ret.size()==count) break;
            for(int i=circle+1;i<row-1-circle;i++){
                ret.push_back(matrix[i][col-circle-1]);
            }
            if(ret.size()==count) break;
            for(int i=col-circle-1;i>=circle;i--){
                ret.push_back(matrix[row-circle-1][i]);
            }
            if(ret.size()==count) break;
            for(int i=row-circle-2;i>circle;i--){
                ret.push_back(matrix[i][circle]);
            }
            circle++;
        }
        return ret;
    }
};