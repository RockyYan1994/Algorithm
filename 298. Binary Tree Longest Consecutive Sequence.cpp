/*
	方法一：通过传入一个当前cnt和target值判定，
	方法二：通过从下往上来判断。
*/

//version 1(28 ms)
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
    int res;
public:
    int longestConsecutive(TreeNode* root) {
        if (!root) return 0;
        res = 0;
        reversePreOrder(root, 0, root->val);
        return res;
    }
    
    void reversePreOrder(TreeNode* root, int cnt, int target) {
        if (!root) return;
        if (root->val == target) cnt++;
        else cnt = 1;
        res = max(res, cnt);
        if (root->left) reversePreOrder(root->left, cnt, root->val + 1);
        if (root->right) reversePreOrder(root->right, cnt, root->val + 1);
    }
};

//version 2(28 ms)
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        int res = 0;
        reversePreOrder(root, res);
        return res;
    }
    
    int reversePreOrder(TreeNode* root, int& res) {
        if (!root) return 0;
        int l = 1, r = 1;
        if (root->right){
            r = reversePreOrder(root->right, res) + 1;
            if (root->val + 1 != root->right->val) r = 1;
        }
        if (root->left) {
            l = reversePreOrder(root->left, res) + 1;
            if (root->val + 1 != root->left->val) l = 1;
        }
        res = max(res, max(l, r));
        return max(l, r);
    }
};

//version 3(16 ms)
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        int len = 0;
        return reversePreOrder(root, nullptr, len);
    }
    
    int reversePreOrder(TreeNode* root, TreeNode* parent, int len) {
        if (!root) return len;
        int cur = parent && root->val == parent->val + 1 ? len + 1 : 1;
        return max(len, max(reversePreOrder(root->left, root, cur), reversePreOrder(root->right, root, cur)));
    }
};