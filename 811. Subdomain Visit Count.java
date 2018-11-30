/*

*/

//version 1(45 ms)
class Solution {
    public List<String> subdomainVisits(String[] cpdomains) {
        List<String> res = new ArrayList();
        Map<String, Integer> M = new HashMap();
        for (String domain : cpdomains) {
            helper(domain, M);
        }
        for (Map.Entry<String, Integer> pair : M.entrySet()) {
            res.add(pair.getValue() + " " + pair.getKey());
        }
        return res;
    }
    
    private static void helper(String domain, Map<String, Integer> M) {
        String[] ss = domain.split("[ .]");
        StringBuilder sb = new StringBuilder();
        for (int i = ss.length - 1; i > 0; i--) {
            if (i != ss.length - 1) {
                sb.insert(0, '.');
            }
            sb.insert(0, ss[i]);
            M.put(sb.toString(), M.getOrDefault(sb.toString(), 0) + Integer.valueOf(ss[0]));
        }        
    }
}