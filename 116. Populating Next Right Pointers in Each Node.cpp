/*
	采用通过上一层修改下一层的方法来实现，也可以采用迭代的方法实现，需要使用一个指针来记录每一层的开头。
*/

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        if(root->left) root->left->next = root->right;
        if(root->right && root->next) root->right->next = root->next->left; 
        if(root->left) connect(root->left);
        if(root->right) connect(root->right);
    }
};



//version 2（from ragepyre）
void connect(TreeLinkNode *root) {
    if (root == NULL) return;
    TreeLinkNode *pre = root;
    TreeLinkNode *cur = NULL;
    while(pre->left) {
        cur = pre;
        while(cur) {
            cur->left->next = cur->right;
            if(cur->next) cur->right->next = cur->next->left;
            cur = cur->next;
        }
        pre = pre->left;
    }
}