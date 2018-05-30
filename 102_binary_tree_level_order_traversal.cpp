/*
*	想到采用BFS来遍历，用一个queue纪录每一层的节点。
*
*/

//version 1(9 ms)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int> > ret;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            TreeNode *cur;
            for(int i=0;i<size;i++){
                cur = q.front();
                q.pop();
                if(!cur) continue;
                q.push(cur->left);
                q.push(cur->right);
                temp.push_back(cur->val);
            }
            if(!temp.empty()) ret.push_back(temp);
        }
        return ret;
    }
};