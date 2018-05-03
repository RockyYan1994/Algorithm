/*
地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，
但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？

这个问题可以用backtracking来解决，通过用一个boolmap来标记已经查看过的点，然后判断条件来限定范围，就能得出结果。
*/

//version 1(3 ms)
class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        vector<vector<bool> > flag(rows,vector<bool>(cols,false));
        return count(threshold,rows,cols,flag,0,0);
    }
    int count(int threshold, int rows, int cols, vector<vector<bool> >& flag, int i, int j){
        if(i<0 || j<0 || i>=rows || j>=cols || flag[i][j] || getSum(i)+getSum(j) > threshold) return 0;
        flag[i][j] = true;
        return (count(threshold,rows,cols,flag,i+1,j)
               +count(threshold,rows,cols,flag,i,j+1)
               +count(threshold,rows,cols,flag,i-1,j)
               +count(threshold,rows,cols,flag,i,j-1)
               +1);
    }
    int getSum(int num){
        int sum = 0;
        while(num>0){
            sum += num%10;
            num /= 10;
        }
        return sum;
    }
};