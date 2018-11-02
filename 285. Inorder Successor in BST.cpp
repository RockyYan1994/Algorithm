/*
	方法一：通过中序遍历。如果出现了对应元素，再进行一次操作。
	方法二：通过递归，如果小酒找右边。如果大则找左边的最小，如果没有则返回root自身。
*/

//version 1(16 ms)
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root) return NULL;
        stack<TreeNode*> s;
        int end = INT_MAX;
        TreeNode* cur = root;
        while (!s.empty() || cur) {
            if (cur) {
                s.push(cur);
                cur = cur -> left;
                continue;
            }
            cur = s.top();
            if (cur == p) end = 1;
            s.pop();
            if (end == 0) return cur;
            cur = cur -> right;
            end--;
        }
        return cur ;
    }
};

//version 2(16 ms)
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root) return NULL;
        
        if (root->val <= p->val) {
            return inorderSuccessor(root->right, p);
        } else {
            TreeNode* left = inorderSuccessor(root->left, p) ;
            return left ? left : root;
        }
    }
};