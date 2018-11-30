/*
	方法一：直接用BFS实现，超时
	方法二：优化查找下一个单词过程，通过一个Map<String, List<String>> 直接找到下一组words，空间太大。
	方法三：通过记录每个单词的degree，也就是最早出现的位置，进行剪枝，通过。
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

//version 2(MLE)
class Solution {
    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        List<List<String>> res = new ArrayList<>();
        if (wordList.isEmpty() || beginWord.length() != endWord.length()) return res;
        
        Queue<List<String>> paths = new LinkedList<>();        
        Set<String> W = new HashSet<>(wordList);
        Map<String, List<String>> dict = buildWordDict(beginWord, wordList);
        int level = 0, minLevel = Integer.MAX_VALUE;
        boolean found = false;
        paths.add(Arrays.asList(beginWord));
        
        while (!paths.isEmpty()) {
            List<String> path = paths.poll();
            if (path.size() >= minLevel) continue;
            Set<String> visited = new HashSet<>(path);
            
            String word = path.get(path.size()-1);
            for (String next : dict.get(word)) {
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
        }
        return res;
    }
    
    private Map<String, List<String>> buildWordDict(String beginWord, List<String> wordList) {
        Map<String, List<String>> M = new HashMap<>();
        Set<String> S = new HashSet<>(wordList);
        wordList.add(beginWord);
        for (String word : wordList) {
            M.put(word, new ArrayList<>());
            StringBuilder sb = new StringBuilder(word);
            for (int i=0; i<word.length(); i++) {
                char temp = sb.charAt(i);
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    sb.setCharAt(i, ch);
                    String next = sb.toString();                    
                    if (S.contains(next)) {                                                
                        M.get(word).add(next);
                    }
                }
                sb.setCharAt(i, temp);
            }            
        }
        return M;
    }
}

//version 3(220 ms)
class Solution {
    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        List<List<String>> res = new ArrayList<>();
        if (wordList.isEmpty() || beginWord.length() != endWord.length()) return res;
        
        Queue<List<String>> paths = new LinkedList<>();        
        Set<String> W = new HashSet<>(wordList);
        Map<String, Integer> degree = new HashMap<>();
        degree.put(beginWord, 1);
        for (String word : wordList) {
            degree.put(word, wordList.size() + 1);
        }
        Map<String, List<String>> dict = buildWordDict(beginWord, wordList);
        int level = 0, minLevel = Integer.MAX_VALUE;
        boolean found = false;
        paths.add(Arrays.asList(beginWord));
        
        while (!paths.isEmpty()) {
            List<String> path = paths.poll();
            if (path.size() >= minLevel) continue;
            String word = path.get(path.size()-1);
            Set<String> visited = new HashSet<>(path);                        
            for (String next : dict.get(word)) {                
                if (!visited.contains(next) && W.contains(next)) {
                    List<String> newPath = new ArrayList<>(path);
                    newPath.add(next);
                    if (degree.get(next) < newPath.size()) continue;
                    else if (degree.get(next) > newPath.size()) degree.put(next, newPath.size());
                    if (next.equals(endWord)) {
                        res.add(newPath);
                        minLevel = newPath.size();
                    } else {
                        paths.add(newPath);
                    }
                }
            }
        }
        return res;
    }
    
    private Map<String, List<String>> buildWordDict(String beginWord, List<String> wordList) {
        Map<String, List<String>> M = new HashMap<>();
        Set<String> S = new HashSet<>(wordList);
        wordList.add(beginWord);
        for (String word : wordList) {
            M.put(word, new ArrayList<>());
            StringBuilder sb = new StringBuilder(word);
            for (int i=0; i<word.length(); i++) {
                char temp = sb.charAt(i);
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    sb.setCharAt(i, ch);
                    String next = sb.toString();                    
                    if (S.contains(next)) {                                                
                        M.get(word).add(next);
                    }
                }
                sb.setCharAt(i, temp);
            }            
        }
        return M;
    }
}