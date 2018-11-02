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
    int cnt;
public:
    int countUnivalSubtrees(TreeNode* root) {
        cnt = 0;
        if (!root) return cnt;
        helper(root);
        return cnt;
    }
    
    bool helper(TreeNode* root) {
        // leaf node, cnt+1, 
        if (!root->left && !root->right) {
            cnt++;
            return true;
        }
        bool l = !root->left || (helper(root->left) && root->val == root->left->val);
        bool r = !root->right || (helper(root->right) && root->val == root->right->val);
        cnt = l && r ? cnt + 1 : cnt;
        return l && r;
    }
};