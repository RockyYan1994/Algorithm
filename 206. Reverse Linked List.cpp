/*
	1， 迭代实现，采用一个preHead来将cur指向的点加在preHead的next。
	2， 迭代实现，避免分配一个新的头
	3， 递归实现，主要问题就是在调用的时候head->next 指向的是返回新list的尾。
*/

//version 1(9 ms)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* preHead = new ListNode(0);
        ListNode* cur = head, *temp;
        while(cur){
            temp = cur->next;
            cur->next = preHead->next;
            preHead->next = cur;
            cur = temp;
        }
        return preHead->next;
    }
};

//version 2(9 ms)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* preHead = nullptr;
        ListNode* cur = head, *temp;
        while(cur){
            temp = cur->next;
            cur->next = preHead;
            preHead = cur;
            cur = temp;
        }
        return preHead;
    }
};

//version 3(9 ms)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* node = reverseList(head->next);
        head->next->next = head; // head->next is the reversed list's new tail, and we need to set head as tail->next
        head->next = nullptr;    // after set head as the new tail, set head -> next to nullptr
        return node;
    }
};