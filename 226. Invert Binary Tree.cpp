/*
	方法一：通过递归调用，然后把左右交换的方法实现，注意这里有一个坑，不能直接
		root->left = invertTree(root->right)；
		root->right= invertTree(root->left);
		这样left导致left已经被修改，会出错。
	方法二：通过迭代实现.
	方法三：把每一个需要交换顺序的node入栈，挨个实现。
*/

//version 1
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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        TreeNode* l = invertTree(root -> right);
        TreeNode* r = invertTree(root -> left);
        root -> left = l;
        root -> right = r;
        return root;
    }
};

//version 2
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        TreeNode* cur = root;
        stack<TreeNode*> s;
        while(!s.empty() || cur) {
            if (cur) {
                s.push(cur);
                cur = cur->left;
            } else {
                cur = s.top();
                s.pop();
                swap(cur->left, cur->right);
                cur = cur -> left;
            }
        }
        return root;
    }
};

//version 3
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()) {
            TreeNode* cur = s.top();
            s.pop();
            if (cur) {
                s.push(cur->left);
                s.push(cur->right);
                swap(cur->left, cur->right);
            }
        }
        return root;
    }
};