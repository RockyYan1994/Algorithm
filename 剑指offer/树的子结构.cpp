/*
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot2 == NULL || pRoot1 == NULL) return false;
        return isSubtree(pRoot1,pRoot2)||HasSubtree(pRoot1->left,pRoot2)||HasSubtree(pRoot1->right,pRoot2);
    }
    bool isSubtree(TreeNode* root1,TreeNode* root2){
        if(root2 == NULL) return true;
        if(root1 == NULL) return false;
        if(root1->val == root2->val){
            return isSubtree(root1->left,root2->left) && isSubtree(root1->right,root2->right);
        }
        else return false;
    }
};