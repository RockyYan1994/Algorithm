/*
	查看了discussion，发现能够采用递归的方法，并且只用O(n)实现。思路就是先递归调用，生成左边节点，然后构建当前节点，最后递归调用生成右边节点。
	关键点在于通过一个node节点记录当前应该构建的节点的位置。
*/


class Solution {
    ListNode* node;
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        this->node = head;
        
        ListNode* temp = head;
        int end = 0;
        while(temp){
            temp = temp->next;
            end++;
        }
        
        TreeNode* root = buildHelper(0,end-1);
        return root;
    }
    TreeNode* buildHelper(int start, int end)
    {
        if(start>end) return NULL;

        int mid = start + (end-start)/2;
        
        TreeNode* root = new TreeNode(0);
        root->left = buildHelper(start,mid-1);
        root->val = node->val;
        this->node = this->node->next;
        root->right = buildHelper(mid+1, end);
        
        return root;
    }
};