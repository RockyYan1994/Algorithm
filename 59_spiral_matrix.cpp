/*
    first
    首先想到通过按照每一圈的方式从外向内添加元素。
*/

//version 1(5 ms)
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > res(n,vector<int>(n,0));
        int round = 0,count=0;
        while(n-2*round>0){
            for(int j=round;j<n-round;j++){
                res[round][j] = ++count; 
            }
            for(int j=round+1;j<n-round;j++) res[j][n-1-round] = ++count;
            
            for(int j=n-2-round;j>=round;j--) res[n-1-round][j] = ++count;
            
            for(int j=n-2-round;j>=round+1;j--) res[j][round] = ++count;
            
            round++;
        }
        return res;
    }
};