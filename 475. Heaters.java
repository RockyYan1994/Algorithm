/*

*/

//version 1()
class Solution {
    public int findRadius(int[] houses, int[] heaters) {
        int res = 0;
        Arrays.sort(heaters);
        for (int house : houses) {
            int index = binarySearch(heaters, house);
            //System.out.println(house + ", " + index);
            int marginLeft = index <= 0 ? Integer.MAX_VALUE : house - heaters[index - 1];
            int marginRight = index >= heaters.length ? Integer.MAX_VALUE : heaters[index] - house;
            
            res = Math.max(res, Math.min(marginLeft, marginRight));
        }
        return res;
    }
    
    private int binarySearch(int[] heaters, int pos) {
        int l = 0, r = heaters.length - 1;        
        while (l <= r) {            
            int mid = l + (r - l) / 2;
            if (heaters[mid] == pos) {
                return mid;
            } else if (heaters[mid] > pos) {
                r = mid - 1;                
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}