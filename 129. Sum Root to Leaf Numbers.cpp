/*

*/

//version 1(4 ms)
class Solution {
    int sum;
public:
    int sumNumbers(TreeNode* root) {
        sum = 0;
        helper(root, 0);
        return sum;
    }
    void helper(TreeNode* root, int val){
        if(!root) return;
        if(!root->left && !root->right){
            val = val*10 + root->val;
            sum += val;
            return;
        }
        val = val*10 + root->val;
        helper(root->left, val);
        helper(root->right, val);
    }
};