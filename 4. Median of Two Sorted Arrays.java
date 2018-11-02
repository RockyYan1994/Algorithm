/*

*/

//version 1(32 ms)
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {        
        if (nums1.length > nums2.length) {
            int[] temp = nums1;
            nums1 = nums2;
            nums2 = temp;            
        }
        int m = nums1.length, n = nums2.length;
        int min = 0, max = m, half = (m+n+1)/2;
        while (min <= max) {
            int i = (min + max)/2;
            int j = half - i;
            if (i > min && nums1[i-1] > nums2[j]) {
                max = i - 1;
            } else if (i < max && nums1[i] < nums2[j-1]) {
                min = i + 1;
            } else {
                int left = 0;
                if (i == 0) left = nums2[j-1];
                else if (j == 0 ) left = nums1[i-1];
                else left = Math.max(nums1[i-1], nums2[j-1]);
                if ((m+n) % 2 == 1) return left;                
                int right = 0;
                if (i == m) right = nums2[j];
                else if (j == n) right = nums1[i];
                else right = Math.min(nums1[i], nums2[j]);
                return (left + right) / 2.0;
            }            
        }
        return 0;
    }
}