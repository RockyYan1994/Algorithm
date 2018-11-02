/*

*/

//version 1()
/* The guess API is defined in the parent class GuessGame.
   @param num, your guess
   @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
      int guess(int num); */

public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int l = 1, r = n;
        while(l <= r) {
            int mid = l + (r-l)/2;
            int ret = guess(mid);
            if (ret == 0) {
                return mid;
            } else if (ret < 0) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }
}