/*
*	这道题主要采用了中序遍历的方法，在实现的过程中，通过判断前后两个元素的值关系，如果违反inorder的规律则保存这个元素，最后替换，使用这个方法基于只有两个
*	元素存在乱序，也可以采用morris的方法来实现。
*
*/

//version 1(65 ms)
class Solution {
    TreeNode *pre = new TreeNode(INT_MIN);
    TreeNode *first=NULL,*second=NULL;
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
    void inorder(TreeNode* root){
         if(!root) return;
        inorder(root->left);
        if(!first && pre->val > root->val) first = pre;
        if(first && pre->val > root->val) second = root;
        pre = root;
        inorder(root->right);
    }
};