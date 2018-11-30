/*

*/

//version 1()
class Solution {

    private Random random;
    private int[] sum;
    
    public Solution(int[] w) {        
        sum = new int[w.length];        
        int temp = 0;
        for (int i = 0; i < w.length; i++) {
            temp += w[i];
            sum[i] = temp;
        }
    }
    
    public int pickIndex() {
        // range: [1, sum[sum.length-1]].
        random = new Random();
        int val = random.nextInt(sum[sum.length - 1]) + 1;
        return binarySearch(val);
    }
    
    private int binarySearch(int val) {
        int l = 0, r = sum.length - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (sum[mid] == val) {
                return mid;
            } else if (sum[mid] > val) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */