/*
	首先统计两个链表的长度，如果存在交点，就会在遍历lenA+lenB之后找到，否则就没有。
*/

//verison 1(24 ms)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return nullptr;
        int lenA = 0;
        int lenB = 0;
        ListNode *curA = headA;
        ListNode *curB = headB;
        while(curA) {
            lenA++;
            curA = curA -> next;
        }
        while(curB) {
            lenB++;
            curB = curB -> next;
        }
        curA = headA;
        curB = headB;
        for(int i=0;i<=lenA+lenB;i++) {
            if(curA == curB) return curA;
            curA = curA ? curA->next : headB;
            curB = curB ? curB->next : headA;
        }
        
        return nullptr;
    }
};