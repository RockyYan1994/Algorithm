/*
	采用DFS的方法，注意在判断条件的时候需要判断是否是叶子。
*/
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        return backtracking(root,sum);
    }
    bool backtracking(TreeNode* root, int sum)
    {
        if(!root) return false;
        if(root->val == sum && !root->left && !root->right) return true;
        
        return backtracking(root->left, sum - root->val) || backtracking(root->right, sum - root->val);
    }
};