/*
	这个问题的思路就是通过创建Trie树，而比较词的方法采用dfs即可。
*/

class Solution {
    class Trie {
        public:
        int idx;
        Trie* children[26];
        bool leaf;
        Trie() {
            this->idx = -1;
            leaf = false;
            memset(this->children, 0, 26*sizeof(Trie*));
        }
    };
public:
    void insertWord(Trie* root, string word, int index) {
        int n = word.size();
        for(int i=0;i<n;i++) {
            if(!root->children[word[i]-'a']) root->children[word[i]-'a'] = new Trie();
            root = root->children[word[i]-'a'];
        }
        root->idx = index;
        root->leaf = true;
    }
    
    Trie* buildTrie(vector<string>& words) {
        Trie* root = new Trie();
        for(int i=0;i<words.size();i++) {
            insertWord(root, words[i], i);
        }
        return root;
    }
    
    void checkTrie(vector<string>& res, vector<string>& words, Trie* root, int i, int j, vector<vector<char>>& board) {
        if(board[i][j] == '.') return;
        
        char temp = board[i][j];
        if(root->children[temp - 'a']) {
            if(root->children[temp-'a']->leaf) {
                res.push_back(words[root->children[temp -'a']->idx]);
                root->children[temp-'a']->leaf = false;
            }
            board[i][j] = '.';

            if(i>0) checkTrie(res, words, root->children[temp-'a'], i-1, j, board);
            if(j>0) checkTrie(res, words, root->children[temp-'a'], i, j-1, board);
            if(i<board.size()-1) checkTrie(res, words, root->children[temp-'a'], i+1, j, board);
            if(j<board[0].size()-1) checkTrie(res, words, root->children[temp-'a'], i, j+1, board);

            board[i][j] = temp;
        }
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if(board.empty()) return res;
        if(board[0].empty()) return res;
        Trie* root = buildTrie(words);
        
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[0].size();j++) {
                checkTrie(res, words, root, i, j, board);
            }
        }
        return res;
    }
    
    
};