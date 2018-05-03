/*
非递归方法没有通过，，没找出来原因。。
递归方法参考了评论区的一个答案，关键点在于pre传的是指针的引用。
*/

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL) return NULL;
        stack<TreeNode*> s;
        s.push(pRootOfTree);
        TreeNode *pre = NULL , *cur = pRootOfTree , *ret;
        while(!s.empty()){
            if(cur) {
                s.push(cur);
                cur = cur->left; 
            }
            else{
                cur = s.top();
                s.pop();
                cout<<pre<<","<<cur<<endl;
                cur->left = pre;
                if(pre) pre->right = cur;
                else ret = cur;
                pre = cur;
                cur = cur->right;
            }
        }
        return ret;
    }
};
#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
int main(int argc, char const *argv[])
{
    Solution s;
    TreeNode* root = new TreeNode(3);
    TreeNode* left = new TreeNode(1);
    TreeNode* right = new TreeNode(5);   
    root->left = left;
    root->right = right;
    s.Convert(root);
    return 0;
}

//version 2(2 ms)
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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL) return NULL;
        TreeNode *pre = NULL, *cur = pRootOfTree;
        inorder(cur,pre);
        TreeNode* ret = pRootOfTree;
        while(ret->left){
            ret = ret->left;
        }
        return ret;
    }
    void inorder(TreeNode* cur, TreeNode*& pre){
        if(cur == NULL) return;
        inorder(cur->left,pre);
        cur->left = pre;
        if(pre) pre->right = cur;
        pre = cur;
        inorder(cur->right,pre);
    }
};
