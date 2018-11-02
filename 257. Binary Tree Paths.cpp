/*

*/


//version 1(4 ms)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root) return res;
        backtracking(res, root, "");
        for (int i=0; i<res.size(); i++) {
            if (res[i][0] == '-') res[i].erase(0, 2);
        }
        return res;
    }
    
    void backtracking(vector<string>& res, TreeNode* root, string s) {
        s = s + "->" + to_string(root->val);
        if (root->left) backtracking(res, root->left, s);
        if (root->right) backtracking(res, root->right, s);
        if (!root->left && !root->right) res.push_back(s);
    }
};