/*
*	这个题可以有recursion和iterate两种方法来实现，第一个版本是递归版本。迭代可以采用队列或者栈的方法来实现。
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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isSymmetricHelper(root->left,root->right);
    }
    bool isSymmetricHelper(TreeNode* left, TreeNode* right){
        if(!left || !right) return left == right;
        return left->val == right->val && isSymmetricHelper(left->left,right->right) && isSymmetricHelper(left->right,right->left);
    }
};

//version 2(9 ms)
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> l,r;
        l.push(root);
        r.push(root);
        while(!l.empty() && !r.empty()){
            int lsize = l.size(), rsize = r.size();
            if(lsize!=rsize) return false;
            TreeNode *lcur,*rcur;
            for(int i=0;i<lsize;i++){
                lcur = l.front();
                rcur = r.front();
                if(!lcur && !rcur){
                    l.pop();
                    r.pop();
                    continue;
                }
                else if(!lcur || !rcur || lcur->val != rcur->val) return false;
                l.push(lcur->left);
                l.push(lcur->right);
                r.push(rcur->right);
                r.push(rcur->left);
                l.pop();
                r.pop();
            }
        }
        return true;
    }
};
