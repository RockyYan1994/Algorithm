/*
	方法一：可以抽象成公式： buckets <= (minutesToTest / minutesToDie + 1) ^ pigs;
*/

//version 1(0 ms)
class Solution {
    public int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        if (minutesToDie > minutesToTest) return -1;
        int times = (minutesToTest / minutesToDie + 1) ;
        int pigs = 0, cnt = 1;        
        while (cnt < buckets) {
            cnt = cnt * times;
            pigs++;
        }
        return pigs;
    }
}