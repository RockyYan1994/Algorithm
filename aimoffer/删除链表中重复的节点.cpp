/*
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5

*/

//version 1(5 ms)
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == NULL) return NULL;
        ListNode **cur = &pHead;
        int val;
        while(*cur != NULL){
            if((*cur)->val == val){
                val = (*cur)->val;
                *cur = (*cur)->next;
            } 
            else if((*cur)->next != NULL && (*cur)->val == (*cur)->next->val) val = (*cur)->val;
            else cur = &((*cur)->next);
        }
        return pHead;
    }
};