/*
	基础的想法就是通过每次找到数组中间的那个值作为root，然后通过递归调用生成左右节点。
*/

//version 1(12 ms)
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return NULL;
        TreeNode* root = helper(nums, 0, nums.size()-1);
        return root;
    }
    TreeNode* helper(vector<int>& nums, int start, int end)
    {
        if(start>end) return NULL;
        int mid = (start+end)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left  = helper(nums, start, mid-1);
        root->right = helper(nums, mid+1, end  );
        return root;
    }
};