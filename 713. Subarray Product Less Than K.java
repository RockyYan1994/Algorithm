/*
	方法一：brute force，直接采用两层循环实现
	方法二：滑动窗口，重点在于把j当作最后一个，然后i往后收缩。
*/

//version 1(TLE)
class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        long temp = 1;      
        int res = 0;
        
        for (int i = 0; i < nums.length; i++) {
            for (int j = i; j < nums.length; j++) {
                if (i == j) {
                    temp = nums[j];
                    res += temp < k ? 1 : 0;
                    continue;
                }
                
                if (temp == -1) {                    
                    continue;
                }
                long ans = temp * nums[j];
                temp = ans > k ? -1 : ans;
                if (ans < k) {
                    res++;
                }
            }
        }
        return res;
    }
}

//version 2(25 ms)
class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        long prod = 1;
        int res = 0;
        for (int i = 0, j = 0; j < nums.length; j++) {
            prod *= nums[j];
            while (i <= j && prod >= k) {
                prod /= nums[i++];
            }
            res += j - i + 1;
        }
        return res;
    }
}