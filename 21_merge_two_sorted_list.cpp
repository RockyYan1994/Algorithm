/*
	first
	首先想到使用一个新的头，然后将两个链表上的数据挨个按照大小链接上去，直到一方为NULL，然后把剩余的链接到最后。
*/
//version 1(10 ms)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode new_head(-1);
        ListNode* pos = &new_head;
        
        while(l1!=NULL&&l2!=NULL){
            if(l1->val>l2->val){
                pos->next = l2;
                l2 = l2->next;
                pos = pos->next;
            }
            else{
                pos->next = l1;
                l1 = l1->next;
                pos = pos->next;            
            }
        }
        if(l1!=NULL){
            pos->next = l1;
        }
        else if(l2!=NULL){
            pos->next = l2;
        }
        return new_head.next;
    }
};