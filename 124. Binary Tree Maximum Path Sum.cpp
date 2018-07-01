/*
	主要想法是通过采用递归方法，每次返回下一层的最大值，如果小于零则返回零，并且用一个maxVal的变量来记录下每个sequence的可能的最大值。
	但是下层返回上层的返回值有三种情况，一是只返回当前节点值，二是返回当前节点加上左边返回值，三是当前节点加上右边返回值。查看discussion 之后
	发现可以在实现上有一个优化，就是在返回left的时候先判断是否大于零，如果小于零则置0.
*/


class Solution {
    int maxVal;
public:
    int maxPathSum(TreeNode* root) {
        maxVal = root->val;
        helper(root);
        return maxVal;
    }
    int helper(TreeNode* root){
        if(!root) return 0;
        int left  = helper(root->left);
        int right = helper(root->right);
        int temp = root->val;
        if(left>0) temp += left;
        if(right>0) temp += right;
        maxVal = max(maxVal, temp);
        int ret = root->val;
        if(left>0 && left>=right) ret += left;
        else if(right>0 && right>left) ret += right;
        ret = ret>0 ? ret:0;
        return ret;
    }
};