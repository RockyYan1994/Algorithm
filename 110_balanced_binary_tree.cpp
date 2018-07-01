/*
    方法一：使用getheight的函数，分别判断左右子树的高。
    方法二：自底向上，也就是DFS，通过一个变量flag，如果存在子树不满足条件，就直接返回。（flag也可以通过helper返回-1的方法来替代）
*/

class Solution {
    bool flag;
public:
    bool isBalanced(TreeNode* root) {
        flag = true;
        helper(root);
        return flag;
    }
    int helper(TreeNode* root){
        if(!root) return 0;
        int left  = helper(root->left );
        if(!flag) return -1;
        int right = helper(root->right);
        if(!flag) return -1;
        if( abs(left-right)>1 ) flag = false;
        return max(left,right) + 1;
    }
};