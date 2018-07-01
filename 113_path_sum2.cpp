/*
	和path sum类似，使用DFS的方法，通过一个path向量来保存当前路径。
*/

version 1(12 ms)
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > ret;
        if(!root) return ret;
        vector<int> temp;
        backtracking(ret, temp, root, sum);
        return ret;
    }
    void backtracking(vector<vector<int> >& ret, vector<int>& path, TreeNode* root, int sum)
    {
        if(!root) return;
        if( root->val==sum && !root->left && !root->right ) {
            path.push_back(root->val);
            ret.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(root->val);
        backtracking(ret, path, root->left, sum-root->val);
        backtracking(ret, path, root->right, sum-root->val);
        path.pop_back();
    }
};