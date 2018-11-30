/*

*/

//version 1(71 ms)
class RandomizedSet {
    
    private Map<Integer, Integer> M;
    
    private List<Integer> L;
    
    private Random random;

    /** Initialize your data structure here. */
    public RandomizedSet() {
        M = new HashMap();
        L = new ArrayList();
        random = new Random();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    public boolean insert(int val) {
        if (M.containsKey(val)) {
            return false;
        } 
        M.put(val, L.size());
        L.add(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    public boolean remove(int val) {
        if (!M.containsKey(val)) {
            return false;
        }
        if (M.get(val) < L.size() - 1) {
            int last = L.get(L.size() - 1);
            M.put(last, M.get(val));
            L.set(M.get(val), last);
        }
        M.remove(val);
        L.remove(L.size() - 1);
        return true;
    }
    
    /** Get a random element from the set. */
    public int getRandom() {
        return L.get(random.nextInt(L.size()));
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */