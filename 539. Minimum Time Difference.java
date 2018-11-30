/*

*/

//version 1(33 ms)
class Solution {
    public int findMinDifference(List<String> timePoints) {
        List<Integer> res = new ArrayList<>();
        for (String timePoint : timePoints) {
            int baseTime = convertTime(timePoint);
            res.add(baseTime);
            res.add(baseTime + 1440);
        }
        Collections.sort(res);
        int min = Integer.MAX_VALUE;
        for (int i = 1; i <= res.size(); i++) {
            min = Math.min(min, Math.abs(res.get(i % res.size()) - res.get(i-1)));
        }
        return min;
    }
    
    private int convertTime(String timePoint) {
        String[] times = timePoint.split(":");
        return Integer.parseInt(times[0]) * 60 + Integer.parseInt(times[1]);
    }
}

//version 2(9 ms)
class Solution {
    public int findMinDifference(List<String> timePoints) {
        boolean[] buckets = new boolean[24 * 60];
        for (String timePoint : timePoints) {
            int baseTime = convertTime(timePoint);
            if (buckets[baseTime]) return 0;
            buckets[baseTime] = true;
        }        
        int min = Integer.MAX_VALUE, prev = -1, first = -1, last = -1;
        for (int i = 0; i < 24 * 60; i++) {
            if (buckets[i] && first == -1) {    
                prev = i;
                first = i;
            } else if (buckets[i]) {                
                min = Math.min(min, i - prev);
                prev = i;
                last = i;
            }                        
        }
        
        return Math.min(min, first + 24 * 60 - last);
    }
    
    private int convertTime(String timePoint) {
        String[] times = timePoint.split(":");
        return Integer.parseInt(times[0]) * 60 + Integer.parseInt(times[1]);
    }
}