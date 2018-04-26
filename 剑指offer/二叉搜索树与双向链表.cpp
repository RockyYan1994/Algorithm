/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL) return pRootOfTree;
        stack<TreeNode*> s;
        s.push(pRootOfTree);
        TreeNode *pre = NULL, *ret = pRootOfTree;
        while(!s.empty()){
            TreeNode *cur = s.top();
            if(cur->left) {
                s.push(cur->left); 
                continue;
            }
            else{
                cur->left = pre;
                if(pre) pre->right = cur;
                else ret = cur;
                s.pop();
                pre = cur;
                if(cur->right) s.push(cur->right);
            }
        }
        return ret;
    }
};