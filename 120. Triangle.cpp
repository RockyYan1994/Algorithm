/*
	查看discussion之后，发现可以通过从下往上的方法，不断找出经过每个节点的最短路径，最后到达顶点。
	最基本的方法是从头向下，把每条路径计算出来，然后遍历找出最短的路径。
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        vector<int> temp(triangle.back());
        for(int i=row-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                temp[j] = triangle[i][j] + min(temp[j],temp[j+1]);
            }
        }
        return temp[0];
    }
};