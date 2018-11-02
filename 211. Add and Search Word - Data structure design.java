/*

*/

//version 1()
class WordDictionary {
    private Trie root;
    /** Initialize your data structure here. */
    public WordDictionary() {
        root = new Trie();
    }
    
    /** Adds a word into the data structure. */
    public void addWord(String word) {
        Trie cur = root;
        for (int i=0; i<word.length(); i++) {
            int idx = word.charAt(i) - 'a';
            if (cur.children[idx] == null) {
                cur.children[idx] = new Trie();                
            }
            cur = cur.children[idx];
        }
        cur.leaf = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    public boolean search(String word) {
        return match(root, 0, word);
    }
    
    private boolean match(Trie cur, int idx, String word) {
        if (cur == null) return false;
        if (idx == word.length() && cur.leaf) return true;
        if (idx == word.length()) return false;
        if (word.charAt(idx) == '.') {
            for (int i=0; i<26; i++) {
                if (cur.children[i] != null && match(cur.children[i], idx+1, word)) return true;
            }
        } else {
            return match(cur.children[word.charAt(idx)-'a'], idx+1, word);
        }
        return false;
    }
    
    class Trie {
        Trie[] children;
        boolean leaf;
        Trie() {
            children = new Trie[26];
            leaf = false;
        }
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */