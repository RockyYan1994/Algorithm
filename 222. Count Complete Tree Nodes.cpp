/*
	方法一：这个问题主要通过高度差来判断，如果右边高度不满足条件，则说明是右边位非完全，如果是左边，则左边位非完全。
	方法二：通过判断是否为一个完全平衡二叉树来计算，如果是则直接返回结果，否则继续往下递归。
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
class Solution {
public:
    int countNodes(TreeNode* root) {
        int h = getHeight(root);
        int cnt = 0;
        while(root) {
            if(getHeight(root->right) == h - 1) {
                cnt += (1 << h);
                root = root -> right;
            } else {
                cnt += (1 << h - 1);
                root = root -> left;
            }
            h--;
        }
        return cnt;
    }
    
    int getHeight(TreeNode* root) {
        return root ? 1 + getHeight(root->left) : -1;
    }
}; 

// version 2(48 ms)
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        TreeNode *l = root, *r = root;
        int lh = 0, rh = 0;
        
        while(l) {l = l -> left; lh++;}
        while(r) {r = r -> right; rh++;}
        
        // completed BT
        if(lh == rh) return (1 << lh) - 1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}; 