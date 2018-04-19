/*
	first:这是一个遍历二叉树的问题，采用中序遍历，不用最简单的递归方法，采用迭代方法，查看discussion之后，采用栈来实现，根据先往左，有则将
	左节点入栈；
	若没有左节点则输出当前节点，然后将当前节点的右节点入栈的方法，可以实现。
	也可以使用morris traveling去遍历，比较于递归和迭代的方法（时间复杂的O(n)、空间复杂度O(n)），morris在使用O(1)空间情况下实现O(n)时间复杂度。
	morris：https://blog.csdn.net/zhaoyunfullmetal/article/details/48087663
	根据我的理解，morris主要分为几种情况，首先查看cur是否存在，若存在则寻找cur->left的最右节点，然后将其最右节点的右节点指向cur，这样就保证在遍历完
	cur的左边之后能够通过最后一个节点返回。之后在进入遍历的过程中，当cur->left存在的情况下，会有两种情况，第一种是还没有找到cur->left的最右节点，
	一种是已经遍历完了cur->left的所有节点。第一种情况下就需要将cur->left最右节点找到并且将其右节点指向cur，第二种情况就需要将指向其cur的右节点删除
	然后输出指向的cur，然后将cur移动到cur->right。另一种情况就是当左节点不存在的情况下，直接输出当前节点的值然后移动当前节点到其右子节点。
*/

//version 1(3 ms)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode *cur = root;

        while(!s.empty() || cur){
            if(cur){
                s.push(cur);
                cur = cur->left;
            }
            else{
                TreeNode *temp = s.top();
                res.push_back(temp->val);
                s.pop();
                cur = temp->right;
            }
        }
        return res;
    }
};


//version 2(3 ms)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *cur = root;
        while(cur){
            if(cur->left == NULL){
                res.push_back(cur->val);
                cur = cur->right;
            }
            else{
                TreeNode *pre = cur->left;
                //find the right most node from cur->left
                while(pre->right != NULL && pre->right != cur) pre = pre->right;
                if(!(pre->right)){
                    pre->right = cur;
                    cur = cur->left;
                }
                else{
                    pre->right = NULL;
                    res.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return res;
    }
};