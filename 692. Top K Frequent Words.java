/*

*/

//version 1(13 ms)
class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        HashMap<String, Integer> M = new HashMap();
        for (String word : words) {
            M.put(word, M.getOrDefault(word, 0) + 1);            
        }
        SortedSet<Map.Entry<String, Integer>> ss = new TreeSet(new Comparator<Map.Entry<String, Integer>>() {
            @Override
            public int compare(Map.Entry<String, Integer> a, Map.Entry<String, Integer> b) {
                if (a.getValue() != b.getValue()) {
                    return b.getValue() - a.getValue();
                } else {
                    return a.getKey().compareTo(b.getKey());
                }
            }
        });
        ss.addAll(M.entrySet());
        List<String> res = new ArrayList();        
        for (Map.Entry<String, Integer> pair : ss) {
            if (k-- == 0) break;
            res.add(pair.getKey());            
        }
        return res;
    }
}

//version 1(from solution)
class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String, Integer> count = new HashMap();
        for (String word: words) {
            count.put(word, count.getOrDefault(word, 0) + 1);
        }
        PriorityQueue<String> heap = new PriorityQueue<String>(
                (w1, w2) -> count.get(w1).equals(count.get(w2)) ?
                w2.compareTo(w1) : count.get(w1) - count.get(w2) );

        for (String word: count.keySet()) {
            heap.offer(word);
            if (heap.size() > k) heap.poll();
        }

        List<String> ans = new ArrayList();
        while (!heap.isEmpty()) ans.add(heap.poll());
        Collections.reverse(ans);
        return ans;
    }
}