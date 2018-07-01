/*
	感觉和morris中序遍历很像，在使用的过程中，如果左边节点存在，就将root右边节点链接到左边子树的最大子节点的右边节点上，然后将root左节点换到右
	节点。
*/

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* cur = root;
        while(cur){
            TreeNode* leftMax = cur->left;
            while(leftMax && leftMax->right) leftMax = leftMax->right;
            if(!leftMax){
                cur = cur->right;
            }
            else{
                leftMax->right = cur->right;
                cur->right = cur->left;
                cur->left  = NULL;
                cur = cur->right;
            }
        }
    }
};