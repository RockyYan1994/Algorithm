/*
给定一颗二叉搜索树，请找出其中的第k大的结点。例如， 5 / \ 3 7 /\ /\ 2 4 6 8 中，按结点数值大小顺序第三个结点的值为4。
感觉这道题主要就使采用一个count计数，然后中序遍历就可以。
*/

//version 1(4 ms)
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
    int count = 0;
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot==NULL) return pRoot;
        stack<TreeNode*> s;
        TreeNode *cur = pRoot; 
        while(!s.empty()||cur){
            if(cur){
                s.push(cur);
                cur = cur->left;
            }
            else{
                count++;
                cur = s.top();
                s.pop();
                if(count == k) return cur;
                cur = cur->right;
            }
        }
        return NULL;
    }

    
};