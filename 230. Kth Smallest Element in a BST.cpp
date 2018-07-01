/*
	采用中序遍历，迭代实现，弹出第k个元素的时候返回该值。
*/

//version 1(16 ms)
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while(!s.empty() || cur){
            while(cur){
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            if(--k == 0) return cur->val;
            s.pop();
            cur = cur->right;
        }
        return 0;
    }
};