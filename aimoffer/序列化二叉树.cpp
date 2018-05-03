/*
请实现两个函数，分别用来序列化和反序列化二叉树
实现主要采用了前序遍历的方法存入，之后用前序遍历的方式取出。
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
class Solution {
public:
    vector<int> buf;
    char* Serialize(TreeNode *root) {    
        buf.clear();
        preSerialize(root);
        int *p = new int[buf.size()];
        for(int i=0;i<buf.size();i++) p[i] = buf[i];
        return (char*)p;
    }
    TreeNode* Deserialize(char *str) {
        int *p = (int*)str;
        return decode(p);
    }
private:
    void preSerialize(TreeNode* cur){
        if(!cur) buf.push_back(0x23333);
        else{
            buf.push_back(cur->val);
            preSerialize(cur->left);
            preSerialize(cur->right);
        }
    }
    TreeNode* decode(int* &pos){
        if(*pos == 0x23333){
            pos++;
            return NULL;
        }
        TreeNode *temp = new TreeNode(*pos);
        pos++;
        temp->left = decode(pos);
        temp->right = decode(pos);
        return temp;
    }
};
