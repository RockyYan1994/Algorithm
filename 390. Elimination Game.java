/*

*/

//version 1(34 ms)
class Solution {
    public int lastRemaining(int n) {
        int left = 1, step = 1, head = 1, remain = n;
        while (remain > 1) {
            if (left == 1 || remain % 2 == 1) {
                head += step;
            }
            step *= 2;
            left = 1 - left;
            remain /= 2;
        }
        return head;
    }
}