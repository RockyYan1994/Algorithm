/*
	主要思路就是找到最左边的点，如果不存在就输出nexts中的top，然后cur移动到当前节点的右边子节点，然后下一次查找的时候先找出最左边节点。
*/

//version 1(12 ms)
class BSTIterator {
    stack<TreeNode*> nexts;
    TreeNode* cur;
public:
    BSTIterator(TreeNode *root) {
        cur = root;
        while(cur) {
            nexts.push(cur);
            cur = cur -> left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return cur || !nexts.empty();
    }

    /** @return the next smallest number */
    int next() {
        if(cur) {
            while(cur) {
                nexts.push(cur);
                cur = cur -> left;
            }
            return next();
        } else {
            cur = nexts.top();
            int ret = cur -> val;
            nexts.pop();
            cur = cur -> right;
            return ret;
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */