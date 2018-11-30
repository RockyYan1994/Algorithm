/*
	方法二：采用两个指针，但是要注意i应该是从n-1到2.
*/

//version 1(60 ms)
class Solution {
    public int triangleNumber(int[] nums) {
        Arrays.sort(nums);
        int cnt = 0;
        for (int i = 0; i < nums.length - 2; i++) {
            for (int j = i+1; j < nums.length - 1; j++) {
                for  (int k = j+1; k < nums.length; k++) {
                    if (nums[k] < nums[j] + nums[i]) {
                        cnt++;
                    } else {
                        break;
                    }
                }
            }        
        }
        return cnt;
    }
}

//version 2(14 ms)
class Solution {
    public int triangleNumber(int[] nums) {
        Arrays.sort(nums);
        int cnt = 0;
        for (int i = nums.length - 1; i >= 2; i--) {
            int l = 0, r = i - 1;
            while (l < r) {
                if (nums[i] < nums[l] + nums[r]) {
                    cnt += r - l;
                    r--;
                } else {
                    l++;
                }
            }
        }
        return cnt;
    }
}