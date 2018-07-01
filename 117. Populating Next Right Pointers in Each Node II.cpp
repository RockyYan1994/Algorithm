/*
	一开始想用递归的方法实现，和116采用类似的方法，但是由于该方法并不是严格层序遍历，这样在上层出现断点的时候就会出现BUG，导致断点之后的节点无法正确连接。
	参照discussion，采用BFS的方法来实现，用head指针指向下一层开头，tail指向下一层末尾，cur指向当前层当前节点。
*/

//version 1(27 ms)
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *cur = root, *head , *tail;
        head = tail = NULL;
        while(cur){
            if(cur->left){
                if(tail) tail = tail->next = cur->left;
                else head = tail = cur->left;
            }
            if(cur->right){
                if(tail) tail = tail->next = cur->right;
                else head = tail = cur->right;
            }
            if(!cur->next){
                cur = head;
                head = tail = NULL;
            }
            else cur = cur->next;
        }
    }
};