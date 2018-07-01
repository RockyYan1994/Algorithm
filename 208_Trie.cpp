/*

*/

//version 1(83 ms)
class Trie {
public:
    /** Initialize your data structure here. */
    Trie():root_(new TreeNode() ) {
        
    }
    
    ~Trie(){ delete root_; }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TreeNode* cur = root_;
        for(int i=0;i<word.size();i++){
            if(!cur->children[ word[i] - 'a' ]) cur->children[ word[i] - 'a' ] = new TreeNode();
            cur = cur->children[ word[i] - 'a' ];
        }
        cur->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        const TreeNode* p = find(word);
        return p && p->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        const TreeNode* p = find(prefix);
        return p != nullptr;
    }
private:
    struct TreeNode{
        bool isEnd;
        vector<TreeNode*> children;
        
        TreeNode():isEnd(false),children(26,nullptr){}
        ~TreeNode(){
            for(auto child : children){
                if(child) 
                    delete child;
            }
        }
    };
    
    TreeNode* root_;
    
    const TreeNode* find(const string& word) const{
        const TreeNode* cur = root_;
        for(const auto ch : word){
            if(!cur) break;
            cur = cur->children[ch-'a'];
        }
        return cur;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */