/*
	方法一：采用二分查找的方法，通过限制target的范围，然后用valid函数判断是否满足，直到找到最小的点。
	方法二：采用DP方法，二维表示，一维表示分i组， 二维是第几个元素，
*/

//version 1(2 ms)
class Solution {
    public int splitArray(int[] nums, int m) {
        int sum = 0, max = 0;
        for (int num : nums) {
            max = Math.max(max, num);
            sum += num;            
        }
        if (m == 1) return sum;
        int l = max, r = sum;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isValid(nums, m, mid)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
    
    private boolean isValid(int[] nums, int m, int target) {
        int cnt = 1, cur = 0;
        for (int num : nums) {
            if (cur + num > target) {
                cur = num;
                cnt++;
                if (cnt > m) {
                    return false;
                }
            } else {
                cur += num;
            }
        }
        return true;
    }
}

//version 2(25 ms)
class Solution {
    public int splitArray(int[] nums, int m) {
        long[][] D = new long[m+1][nums.length+1];
        for (int i = 1; i <= nums.length; i++) {
            D[0][i] = Integer.MAX_VALUE;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= nums.length; j++) {
                long sum = 0;
                D[i][j] = Integer.MAX_VALUE;
                for (int k = j - 1; k >= 0; k--) {
                    sum += nums[k];
                    D[i][j] = Math.min(D[i][j], Math.max(D[i-1][k], sum));                    
                }
            }
        }
        return (int)D[m][nums.length];
    }
}