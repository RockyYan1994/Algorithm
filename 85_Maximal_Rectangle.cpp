/*
	first
	一开始没有想出来解法，采用的是discussion中第一个解，利用三个数组的DP（height、left、right）来实现计算最大矩形的面积。
*/


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;
        vector<int> height(n,0),left(n,0),right(n,n);
        for(int i=0;i<m;i++){
            int cur_left = 0, cur_right = n;
            for(int j=0;j<n;j++){
                if(matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }
            for(int j=0;j<n;j++){
                if(matrix[i][j] == '1') left[j] = max(left[j],cur_left);
                else {left[j] = 0; cur_left = j+1;}
            }
            for(int j=n-1;j>=0;j--){
                if(matrix[i][j] == '1') right[j] = min(right[j],cur_right);
                else {right[j] = n; cur_right = j;}
            }
            for(int j=0;j<n;j++){
                res = max(res,(right[j]-left[j])*height[j]);
            }
        }
        return res;
    }
};