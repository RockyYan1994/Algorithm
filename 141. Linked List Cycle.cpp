/*
	首先想到用一个cur指向head的next，然后while cur = cur->next, 如果cur和head相同则返回true， 否则返回false。但是这样不能处理链表中间出现环
	的情况。
*/

//version 1(10 ms)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        ListNode *fast = head;
        ListNode* slow = head;
        while(fast && slow){
            if(fast->next) fast = fast->next->next;
            else break;
            slow = slow->next;
            if(fast == slow) return true;
        }
        return false;
    }
};