/*
	1，递归方法，比较容易
	2，迭代方法
	3，morris方法，空间O(1)
*/

//version 1(3 ms)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        ret.clear();
        preorderHelper(root);
        return ret;
    }
private:
    vector<int> ret;
    void preorderHelper(TreeNode* root){
        if(!root) return;
        ret.push_back(root->val);
        preorderHelper(root->left);
        preorderHelper(root->right);
    }
};

//version 2(3 ms)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(!root) return ret;
        stack<TreeNode*> s;
        s.push(root);
        
        while(!s.empty()){
            TreeNode* cur = s.top();
            s.pop();
            ret.push_back(cur->val);
            if(cur->right) s.push(cur->right);
            if(cur->left) s.push(cur->left);
        }
        return ret;
    }
};

//version 3(3 ms)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(!root) return ret;
        TreeNode *temp = root, *pre;
        while(temp){
            if(!temp->left){
                ret.push_back(temp->val);
                temp = temp->right;
            }else{
                pre = temp->left;
                while(pre->right && pre->right != temp) pre = pre->right;
                if(!pre->right){
                    ret.push_back(temp->val);
                    pre->right = temp;
                    temp = temp->left;
                }else{
                    pre->right = NULL;
                    temp = temp->right;
                }
            }
        }
        return ret;
    }
};