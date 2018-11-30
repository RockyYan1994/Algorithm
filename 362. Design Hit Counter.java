/*

*/

//version 1(65 ms)
class HitCounter {

    Queue<Integer> Q;
    
    /** Initialize your data structure here. */
    public HitCounter() {
        Q = new LinkedList<>();
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    public void hit(int timestamp) {
        Q.add(timestamp);
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    public int getHits(int timestamp) {
        while (!Q.isEmpty() && Q.peek() + 300 <= timestamp) {
            Q.poll();
        }
        return Q.size();
    }
}

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */