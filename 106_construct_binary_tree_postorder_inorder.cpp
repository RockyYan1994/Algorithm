/*
	和用先序和中序类似，但是从后面开始考虑
*/

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root = buildTreeHelper(inorder, postorder, 0, inorder.size()-1, postorder.size()-1);
        return root;
    }
    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int infront, int inback, int postback){
        if(postback<0 || infront > inback) return NULL;
        
        TreeNode* root = new TreeNode(postorder[postback]);
        int index;
        for(index = inback; index>=infront ;index--){
            if(inorder[index] == postorder[postback]) break;
        }
        root->left  = buildTreeHelper(inorder, postorder, infront, index-1, postback-inback+index-1);
        root->right = buildTreeHelper(inorder, postorder, index+1, inback, postback-1);
        return root;
    }
};