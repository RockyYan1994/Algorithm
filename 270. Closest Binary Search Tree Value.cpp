/*
	注意这个问题有个坑，不能直接在下一个节点的diff比上一个的diff小的时候就退出，可能存在 1, null, 4, 2。target为1.6的情况。需要找到null才返回结果
	
*/

//version 1(4 ms)
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        if (!root) return 0;
        TreeNode* cur = root;
        int res = root->val;
        while (cur) {
            TreeNode* next = target > cur->val ? cur->right : cur->left;
            if (!next) return res;
            res = abs((double)res - target) < abs((double)(next->val) - target) ? res : next->val;
            cur = next;
        }
        return res;
    }
};

//version 2()
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
    int closestValue(TreeNode* root, double target) {
        if (!root) return 0;
        auto kid = target > root->val ? root->right : root->left;
        if (!kid) return root->val;
        int b = closestValue(kid, target);
        return abs(root->val - target) < abs(b - target) ? root->val : b;
    }
};

//version 2
int closestValue(TreeNode* root, double target) {
    int closest = root->val;
    while (root) {
        if (abs(closest - target) >= abs(root->val - target))
            closest = root->val;
        root = target < root->val ? root->left : root->right;
    }
    return closest;
}