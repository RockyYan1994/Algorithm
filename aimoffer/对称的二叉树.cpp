/*
请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
首先想到采用迭代的方式，用两个queue来保存，但是发现这样每个节点计算了两次，感觉可以通过减半来进行优化。
也可以采用递归的方式来执行
*/

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

//version 1(3 ms)
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        queue<TreeNode*> l,r;
        l.push(pRoot);
        r.push(pRoot);
        while(!l.empty() && !r.empty()){
            int lsize = l.size(),rsize = r.size();
            if(lsize != rsize) return false;
            TreeNode *lcur,*rcur;
            for(int i=0;i<lsize;i++){
                lcur = l.front();
                rcur = r.front();
                if(lcur==NULL && rcur==NULL) {
                    l.pop();
                    r.pop();
                    continue;
                }
                else if(lcur == NULL || rcur == NULL || lcur->val != rcur->val) return false;
                l.push(lcur->left);
                l.push(lcur->right);
                r.push(rcur->right);
                r.push(rcur->left);
                l.pop();
                r.pop();
            }
        }
        return true;
    }

};

//version 2（From Ron）
链接：https://www.nowcoder.com/questionTerminal/ff05d44dfdb04e1d83bdbdab320efbcb
来源：牛客网

public class Solution {
    boolean isSymmetrical(TreeNode pRoot)
    {
        if(pRoot == null){
            return true;
        }
        return comRoot(pRoot.left, pRoot.right);
    }
    private boolean comRoot(TreeNode left, TreeNode right) {
        // TODO Auto-generated method stub
        if(left == null) return right==null;
        if(right == null) return false;
        if(left.val != right.val) return false;
        return comRoot(left.right, right.left) && comRoot(left.left, right.right);
    }
}