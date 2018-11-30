/*
	方法一：主要思路是将tickets转换成Map<String, PriorityQueue<>> 的形式，需要注意的是不能直接按照priorityQueue第一个目的地进行遍历输出，因为可能提前遇到终点

*/

//version 1(6 ms)
class Solution {
    public List<String> findItinerary(String[][] tickets) {
        Map<String, PriorityQueue<String>> M = buildMap(tickets);
        int n = tickets.length;
        List<String> res = new LinkedList<>();        
        dfs(M, res, "JFK");
        return res;
    }
    
    private void dfs(Map<String, PriorityQueue<String>> M, List<String> res, String from) {        
        while (M.containsKey(from) && !M.get(from).isEmpty()) {            
            String to = M.get(from).poll();
            dfs(M, res, to);                                
        }
        res.add(0, from);        
    }
    
    private Map<String, PriorityQueue<String>> buildMap(String[][] tickets) {
        Map<String, PriorityQueue<String>> M = new HashMap();
        for (String[] ticket : tickets) {
            if (!M.containsKey(ticket[0])) {
                M.put(ticket[0], new PriorityQueue<>());
            }
            M.get(ticket[0]).add(ticket[1]);
        }
        return M;
    }
}