/*
* 首先想到采用递归的方法实现,可以有两种不同的写法
*
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//version 1(4ms)
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //check if these two node is equal
        if( p == NULL && q == NULL ) return true;
        else if(p!=NULL && q!=NULL && p->val == q->val) return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        else return false;
    }
};

//version 2 (4ms)
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //check if these two node is equal
        if(p == NULL || q == NULL) return p == q;
        else return p->val == q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};