/*

*/

//version 1(95 ms)
class LogSystem {
    
    private List<String> gras = Arrays.asList("Year", "Month", "Day", "Hour", "Minute", "Second");
    
    private int[] idxs = new int[] {4, 7, 10, 13, 16, 19};
    
    private List<String[]> timestamps;

    public LogSystem() {
        timestamps = new LinkedList<>();
    }
    
    public void put(int id, String timestamp) {
        timestamps.add(new String[] {id + "", timestamp});
    }
    
    public List<Integer> retrieve(String s, String e, String gra) {
        List<Integer> res = new ArrayList<>();
        int idx = idxs[gras.indexOf(gra)];
        for (String[] timestamp : timestamps) {
            if (s.substring(0, idx).compareTo(timestamp[1].substring(0, idx)) <= 0 
                && timestamp[1].substring(0, idx).compareTo(e.substring(0, idx)) <= 0) {
                res.add(Integer.valueOf(timestamp[0]));
            }
        }
        return res;
    }
}

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem obj = new LogSystem();
 * obj.put(id,timestamp);
 * List<Integer> param_2 = obj.retrieve(s,e,gra);
 */