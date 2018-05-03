/*
输入一棵二叉树，判断该二叉树是否是平衡二叉树。
首先想到利用BSF的方法找到数组的深度，对每个点都进行递归判断是否满足条件。然而这样效率有点低下，因为反复计算了很多次数组的深度，感觉可以优化。
第二个解法from julius，通过dep引用来并且采用后序遍历来解决不断计算深度的问题。
*/

//version 1(3 ms)
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(!pRoot) return true;
        if( !IsBalanced_Solution(pRoot->left) || !IsBalanced_Solution(pRoot->right) ) return false;
        int left = deep(pRoot->left);
        int right = deep(pRoot->right);
        if(abs(left-right) <= 1) return true;
        return false;
    }
    int deep(TreeNode* root){
        return root?(max(deep(root->left),deep(root->right))+1):0;
    }
};

//version 2
链接：https://www.nowcoder.com/questionTerminal/8b3b95850edb4115918ecebdf1b4d222
来源：牛客网

//后续遍历二叉树，遍历过程中求子树高度，判断是否平衡
class Solution {
public:
    bool IsBalanced(TreeNode *root, int & dep){
        if(root == NULL){
            return true;
        }
        int left = 0;
        int right = 0;
        if(IsBalanced(root->left,left) && IsBalanced(root->right, right)){
            int dif = left - right;
            if(dif<-1 || dif >1)
                return false;
            dep = (left > right ? left : right) + 1;
            return true;
        }
        return false;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int dep = 0;
        return IsBalanced(pRoot, dep);
    }
};