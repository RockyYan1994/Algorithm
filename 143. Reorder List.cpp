/*
	主要通过三个步骤：
	1， 找到中间节点的前一个节点；
	2， 反转后面链表的顺序
	3， merge两个链表。
*/

//version 1(59 ms)
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next)  return;
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode *mid = slow -> next;
        slow -> next = NULL;
        ListNode *cur = mid -> next;
        mid -> next = NULL;
        while(cur){
            ListNode* next = cur -> next;
            cur->next = mid;
            mid = cur;
            cur = next;
        }
        
        ListNode *l1 = head, *l2 = mid;
        while(l1 && l2){
            ListNode* next = l1 -> next;
            l1 -> next = l2;
            l2 = l2 -> next;
            l1 = l1->next->next = next;
        }
    }
};