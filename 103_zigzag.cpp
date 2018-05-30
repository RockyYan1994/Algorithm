/*

*/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ret;
        if(!root) return ret;
        queue<TreeNode*> s;
        s.push(root);
        bool order = false;
        while(!s.empty()){
            int size = s.size();
            vector<int> temp(size,0);
            for(int i=0;i<size;i++){
                int index = order ? i : size-1-i;
                TreeNode* cur = s.front();
                s.pop();
                temp[index] = cur->val;
                
                if(cur->left) s.push(cur->left);
                if(cur->right) s.push(cur->right);
            }
            order = !order;
            ret.push_back(temp);
        }
        return ret;
    }
};