/*
	方法一：直接计算左右和上下的数量，
*/

//version 1(9 ms)
class Solution {
    public boolean judgeCircle(String moves) {
        int x = 0, y = 0;
        for (char move : moves.toCharArray()) {
            if (move == 'L') {
                x--;
            } else if (move == 'R') {
                x++;
            } else if (move == 'U') {
                y++;
            } else if (move == 'D') {
                y--;
            }
        }
        return x == 0 && y == 0;
    }
}