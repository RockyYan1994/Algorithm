/*
操作给定的二叉树，将其变换为源二叉树的镜像。
一开始总想的是采用队列的方法来实现，发现比较复杂，查看discussion发现采用递归比较简单。
也可以不采用递归的方法来实现，可以通过栈的方法来实现，通过不断把需要左右转换的节点入栈即可
*/

//version 1(3 ms)
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
    void Mirror(TreeNode *pRoot) {
        if(pRoot == NULL) return;
        TreeNode *temp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = temp;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};

class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if(pRoot == NULL) return;
        stack<TreeNode*> s;
        s.push(pRoot);
        while(!s.empty()){
            TreeNode *cur = s.top();
            s.pop();
            TreeNode *temp = cur->left;
            cur->left = cur->right;
            cur->right = temp;
            if(cur->left != NULL) s.push(cur->left);
            if(cur->right != NULL) s.push(cur->right);
        }
    }
};