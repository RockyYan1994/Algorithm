/*
*	这个问题首先有两个思路：
*	1、中序遍历，将结果存到一个vector中，然后判定这个vector是否为有序。这个还能采用迭代的方法实现，主要区别就是设置一个pre记住上一个节点的值。
*	2、递归，通过返回的左右子树中的值来进行判定。
*
*/

//version 1(12 ms)
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
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        vector<int> vals;
        inorder(vals, root);
        for(int i=1;i<vals.size();i++){
            if(vals[i-1]>=vals[i]) return false;
        }
        return true;
    }
    
    void inorder(vector<int>& vals, TreeNode* root){
        if(!root) return;
        if(root->left) inorder(vals, root->left);
        vals.push_back(root->val);
        if(root->right) inorder(vals, root->right);
    }
};

//version 2(10 ms)
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MIN, LONG_MAX);
    }
    
    bool isValid(TreeNode* root, long min, long max){
        if(!root) return true;
        if(root->val <= min || root->val >= max) return false;
        return isValid(root->left, min, root->val) && isValid(root->right, root->val, max);
    }
};