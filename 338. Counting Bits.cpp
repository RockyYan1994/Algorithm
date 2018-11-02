/*
	方法一：遍历0-n，然后通过countBit函数计算。
	方法二：通过dp， dp[i] = dp[i>>1] + (i&1);
*/

//version 1(4 ms)
class Solution {
    public int[] countBits(int num) {
        int[] res = new int[num+1];
        for (int i=1; i<res.length; i++) {
            res[i] = countBit(i);
        }
        return res;
    }
    
    private int countBit(int num) {
        int res = 0;
        while (num != 0) {
            res += num & 1;
            num >>>= 1;
        }
        return res;
    }
}


//version 2(2 ms)
class Solution {
    public int[] countBits(int num) {
        int[] res = new int[num+1];
        for (int i=0; i<res.length; i++) {
            res[i] = res[i/2] + (i&1);
        }
        return res;
    }
}

