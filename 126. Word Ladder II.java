/*

*/

//version 1(TLE)
class Solution {
    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        List<List<String>> res = new ArrayList<>();
        if (wordList.isEmpty() || beginWord.length() != endWord.length()) return res;
        
        Queue<List<String>> paths = new LinkedList<>();
        Set<String> W = new HashSet<>(wordList);        
        int level = 0, minLevel = Integer.MAX_VALUE;
        boolean found = false;
        paths.add(Arrays.asList(beginWord));
        
        while (!paths.isEmpty()) {
            List<String> path = paths.poll();
            if (path.size() >= minLevel) continue;
            Set<String> visited = new HashSet<>(path);
            
            String word = path.get(path.size()-1);
            StringBuilder sb = new StringBuilder(word);
            for (int i=0; i<word.length(); i++) {
                char temp = sb.charAt(i);
                for (char ch='a'; ch<='z'; ch++) {                    
                    sb.setCharAt(i, ch);
                    String next = sb.toString();                    
                    if (!visited.contains(next) && W.contains(next)) {
                        List<String> newPath = new ArrayList<>(path);
                        newPath.add(next);                        
                        if (next.equals(endWord)) {
                            res.add(newPath);
                            minLevel = newPath.size();
                        } else {
                            paths.add(newPath);
                        }
                    }
                }
                sb.setCharAt(i, temp);
            }
        }
        return res;
    }
}