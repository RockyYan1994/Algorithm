/*
	first: 在discussion中找到解法，发现可以利用递归来完成，通过遍历每个节点，然后递归的构造每个节点的递归子树。在discussion中发现一个O(1)
	空间的答案，还没研究。
*/

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
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0){
            vector<TreeNode *> res;
            return res;
        }
        return treeGenerator(1,n);
    }
    
    vector<TreeNode *> treeGenerator(int start,int end){
        vector<TreeNode *> res;
        if(start > end) res.push_back(0);
        if(start == end) res.push_back(new TreeNode(start));
        if(start < end)
        {
            for(int i=start;i<=end;i++)
            {
                vector<TreeNode*> left = treeGenerator(start,i-1);
                vector<TreeNode*> right = treeGenerator(i+1,end);

                for(int m=0;m<left.size();m++)
                {
                    for(int n=0;n<right.size();n++)
                    {
                        TreeNode *root = new TreeNode(i);
                        root->left = left[m];
                        root->right = right[n];
                        res.push_back(root);
                    }
                }
            }
        }
        return res;
    }
};


//version 2(from Wangxinlei)
/*
The basic idea is that we can construct the result of n node tree just from the result of n-1 node tree.
Here’s how we do it: only 2 conditions: 1) The nth node is the new root, so newroot->left = oldroot;
2) the nth node is not root, we traverse the old tree, every time the node in the old tree has a right child, we can perform: old node->right = nth node, nth node ->left = right child; and when we reach the end of the tree, don’t forget we can also add the nth node here.
One thing to notice is that every time we push a TreeNode in our result, I push the clone version of the root, and I recover what I do to the old node immediately. This is because you may use the old tree for several times.
*/
 class Solution {
    public:
        TreeNode* clone(TreeNode* root){
            if(root == nullptr)
                return nullptr;
            TreeNode* newroot = new TreeNode(root->val);
            newroot->left = clone(root->left);
            newroot->right = clone(root->right);
            return newroot;
        }
        vector<TreeNode *> generateTrees(int n) {
            vector<TreeNode *> res(1,nullptr);
            for(int i = 1; i <= n; i++){
                vector<TreeNode *> tmp;
                for(int j = 0; j<res.size();j++){
                    TreeNode* oldroot = res[j];
                    TreeNode* root = new TreeNode(i);
                    TreeNode* target = clone(oldroot);
                    root->left = target;
                    tmp.push_back(root);
                   
                    if(oldroot!=nullptr){
                        TreeNode* tmpold = oldroot;
                        while(tmpold->right!=nullptr){
                            TreeNode* nonroot = new TreeNode(i);
                            TreeNode *tright = tmpold->right;
                            tmpold->right = nonroot;
                            nonroot->left = tright;
                            TreeNode *target = clone(oldroot);
                            tmp.push_back(target);
                            tmpold->right = tright;
                            tmpold = tmpold->right;
                        }
                        tmpold->right = new TreeNode(i);
                        TreeNode *target = clone(oldroot);
                        tmp.push_back(target);
                        tmpold->right = nullptr;
                    }
                }
                res=tmp;
            }
            return res;
        }
    };