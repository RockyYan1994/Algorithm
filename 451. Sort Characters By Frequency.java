/*

*/

//version 1()
class Solution {
    public String frequencySort(String s) {
        Map<Character, Integer> counter = new HashMap<>();
        for (char c : s.toCharArray()) {
            counter.put(c, counter.getOrDefault(c, 0));
        }
        PriorityQueue<int[]> Q = new PriorityQueue<>((a,b) -> b[1] - a[1]);
        for (Map.Entry<Character, Integer> pair : counter) {
            Q.add(new int[] {pair.getKey(), pair.getValue()});
        }
        StringBuilder sb = new StringBuilder();
        while (!Q.isEmpty()) {
            sb.append((char) Q.poll()[0]);
        }
        return sb.toString();
    }
}

//version 2()
public class Solution {
    public String frequencySort(String s) {
        Map<Character, Integer> map = new HashMap<>();
        for (char c : s.toCharArray()) {
            map.put(c, map.getOrDefault(c, 0) + 1);
        }
						
        List<Character> [] bucket = new List[s.length() + 1];
        for (Map.Entry<Character, Integer> pair : map.entrySet()) {
            int f = pair.getValue();
            if (bucket[f] == null) bucket[f] = new ArrayList<>();
            bucket[f].add(pair.getKey());
        }
				
        StringBuilder sb = new StringBuilder();
        for (int pos = bucket.length - 1; pos >= 0; pos--)
            if (bucket[pos] != null)
                for (char c : bucket[pos])
                    for (int i = 0; i < map.get(c); i++)
                        sb.append(c);

        return sb.toString();
    }
}
