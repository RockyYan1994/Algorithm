/*

*/

//version 1(15 ms)
class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        int mid = bs(arr, x);
        int l = mid, r = mid + 1, cnt = 0;
        List<Integer> res = new ArrayList();
        while (cnt < k) {
            if (l >= 0 && (r == arr.length || x - arr[l] <= arr[r] - x)) {
                res.add(arr[l--]);
            } else {
                res.add(arr[r++]);
            }
            cnt++;
        }
        Collections.sort(res);
        return res;
    }
    
    private int bs(int[] arr, int x) {
        int l = 0, r = arr.length - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == x) {
                return mid;
            } else if (arr[mid] > x) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}


//version 2(7 ms)
class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        int l = 0, r = arr.length - k;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (x - arr[mid] > arr[mid + k] - x) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        List<Integer> res = new ArrayList();
        for (int i = l; i < l + k; i++) {
            res.add(arr[i]);
        }
        return res;
    }
}