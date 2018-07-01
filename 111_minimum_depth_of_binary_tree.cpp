/*
	主要是寻找叶子节点，通过BFS查找，采用迭代实现。
	递归方法
*/

version 1(10 ms)
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        int depth = 1;

        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* cur = q.front();
                q.pop();
                if(!cur->left && !cur->right) return depth;
                if( cur->left )  q.push(cur->left);
                if( cur->right ) q.push(cur->right);
            }
            depth++;
        }
        return depth;
    }
};

//version 2(from wulinjiansheng)
class Solution {
public:
    int minDepth(TreeNode *root) {
        if(!root) return 0;
        if(!root->left) return 1 + minDepth(root->right);
        if(!root->right) return 1 + minDepth(root->left);
        return 1+min(minDepth(root->left),minDepth(root->right));
    }
};