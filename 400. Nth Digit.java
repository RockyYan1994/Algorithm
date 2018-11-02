/*

*/

//version 1(3 ms)
class Solution {
    public int findNthDigit(int n) {
        int num = 1, start = 1;
        long base = 9;
        while (n > base * num) {
            n -= base * num;
            num++; 
            base *= 10;
            start *= 10;
        }
        start = start + (n-1)/num;
        String s = Integer.toString(start);
        return (int)(s.charAt((n-1)%num) - '0');
    }
}