/*
	1，利用一个cur来每次插入一个新的节点，每次插入节点的时候，通过从头遍历，找到第一个合适的位置插入。
*/

//version 1(49 ms)
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return NULL;
        ListNode ph = ListNode(-1);
        ListNode* preHead = &ph;
        ListNode *h, *cur = head;
        while(cur){
            ListNode *temp = cur->next;
            h = preHead;
            while(h->next && h->next->val <= cur->val)
                h = h -> next;
            cur -> next = h -> next;
            h -> next = cur;
            cur = temp;
        }
        return preHead -> next;
    }
};