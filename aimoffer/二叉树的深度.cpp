/*
输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
一开始想采用DFS的方法，但是这样需要考虑增加和减少的问题，查看了DFS的方法，发现可以采用BFS的方法，这样可以自然的找到最长的路径。
同时可以有递归和非递归的方法来实现。
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
    int TreeDepth(TreeNode* pRoot)
    {
        if(!pRoot) return 0;
        int max_deep = 0;
        queue<TreeNode*> que;
        que.push(pRoot);
        while(!que.empty()){
            int size = que.size();
            max_deep++;
            for(int i=0;i<size;i++){
                TreeNode* cur = que.front();
                que.pop();
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
        }
        return max_deep;
    }
};

//version 2(2 ms)
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        return pRoot?(max(TreeDepth(pRoot->right),TreeDepth(pRoot->left))+1):0;
    }
};