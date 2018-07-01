/*
	根据Pascal Triangle的性质，每次利用上一行来生成下一行。
*/

//version 1(4 ms)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > ret;
        if(numRows == 0) return ret;
        ret.push_back(vector<int>(1,1));
        for(int i=1;i<numRows;i++){
            vector<int> temp(i+1,1);
            for(int j=1;j<i;j++) temp[j] = ret[i-1][j-1] + ret[i-1][j];
            ret.push_back(temp);
        }
        return ret;
    }
};