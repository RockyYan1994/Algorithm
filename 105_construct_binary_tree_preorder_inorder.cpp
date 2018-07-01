/*
	思路主要就是利用pre作为的元素作为根节点，然后进入inorder里面相应寻找对应的位置，然后分别对这个根递归调用build函数帮助其构建两个子节点。
*/

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(inorder.empty()) return NULL;
        TreeNode* root = buildTreeHelper(preorder, inorder, 0, 0, inorder.size()-1);
        return root;
    }
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int prefront, int infront, int inback){
        if(prefront>preorder.size()-1 || infront>inback) return NULL;
        TreeNode* root = new TreeNode(preorder[prefront]);
        int i;
        for(i=infront;i<=inback;i++){
            if(inorder[i] == preorder[prefront] ) break;
        }
        root->left = buildTreeHelper(preorder, inorder, prefront+1, infront, i-1);
        root->right = buildTreeHelper(preorder, inorder, prefront+i-infront+1, i+1, inback);
        return root;
    }
};