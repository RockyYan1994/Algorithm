/*

*/

//version 1(5 ms)
class Solution {
    public String[] uncommonFromSentences(String A, String B) {
        Map<String, Integer> M = new HashMap();        
        for (String word : A.split(" ")) {
            M.put(word, M.getOrDefault(word, 0) + 1);
        }
        for (String word : B.split(" ")) {
            M.put(word, M.getOrDefault(word, 0) + 1);
        }
        List<String> res = new ArrayList();
        for (Map.Entry<String, Integer> pair : M.entrySet()) {
            if (pair.getValue() == 1) {
                res.add(pair.getKey());
            }
        }
        return res.toArray(new String[res.size()]);
    }
}