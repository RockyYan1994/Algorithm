/*
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
在discussion上找到一个比较清晰的解释 
https://uploadfiles.nowcoder.net/images/20160724/961875_1469289666488_886555C4C4726220976FEF4D3A32FFCD
主要就是先复制每个节点并且加到原节点后面，然后将复制节点的random指针指向原节点random指针的next，最后分离两个链表即可。
*/

/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == NULL) return pHead;
        RandomListNode *cur = pHead;
        while(cur){
            RandomListNode *cp_cur = new RandomListNode(cur->label);
            cp_cur->next = cur->next;
            cur->next = cp_cur;
            cur = cp_cur->next;
        }
        cur = pHead;
        while(cur){
            if(cur->random) cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        RandomListNode *cp_pHead = pHead->next , *temp;
        cur = pHead;
        while(cur->next){
            temp = cur->next;
            cur->next = temp->next;
            cur = temp;
        }
        return cp_pHead;
    }
};