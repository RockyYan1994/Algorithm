/*
	1，采用指针的指针实现
	2，
*/

//version 1(30 ms)
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return nullptr;
        ListNode** cur = &head;
        while( *cur ){
            if((*cur)->val == val) *cur = (*cur)->next;
            else cur = &(*cur)->next;
        }
        return head;
    }
};


//version 2(30 ms)
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return nullptr;
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }
};