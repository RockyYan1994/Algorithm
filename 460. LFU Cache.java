/*

*/

//version 1(107 ms)
class LFUCache {
    
    private Map<Integer, Integer> counter;
    private Map<Integer, Integer> cache;
    private Map<Integer, LinkedHashSet<Integer>> level;
    private int capacity, minLevel;
    
    public LFUCache(int capacity) {
        minLevel = -1;
        this.capacity = capacity;
        counter = new HashMap<>();
        cache = new HashMap<>();
        level = new HashMap<>();
        level.put(1, new LinkedHashSet<>());
    }
    
    public int get(int key) {
        if (!cache.containsKey(key)) {
            return -1;
        }
        int count = counter.get(key);
        counter.put(key, count + 1);
        level.get(count).remove(key);
        if (count == minLevel && level.get(count).isEmpty()) {
            minLevel++;
        }
        if (!level.containsKey(count + 1)) {
            level.put(count + 1, new LinkedHashSet<>());
        }
        level.get(count + 1).add(key);
        return cache.get(key);
    }
    
    public void put(int key, int value) {
        if (capacity <= 0) return ;
        if (cache.containsKey(key)) {
            cache.put(key, value);
            get(key);
            return;
        }        
        if (cache.size() >= capacity) {
            int evict = level.get(minLevel).iterator().next();
            cache.remove(evict);
            level.get(minLevel).remove(evict);
            counter.remove(evict);
        }
        cache.put(key, value);
        counter.put(key, 1);
        minLevel = 1;
        level.get(1).add(key);
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */