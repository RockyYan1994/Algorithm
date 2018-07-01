/*
	1，递归方法
	2，迭代方法，修改先序遍历，使其变成root->right->left，然后reverse结果，就变成后序left->right->root
	3，
*/

//version 1(3 ms)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        ret.clear();
        helper(root);
        return ret;
    }
private:
    vector<int> ret;
    void helper(TreeNode* root){
        if(!root) return;
        helper(root->left);
        helper(root->right);
        ret.push_back(root->val);
    }
};

//version 2（3 ms）
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(!root) return ret;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* cur = s.top();
            s.pop();
            ret.push_back(cur->val);
            if(cur->left) s.push(cur->left);
            if(cur->right) s.push(cur->right);
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};