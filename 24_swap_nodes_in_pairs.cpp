/*
	first
	首先想到使用三个指针分别指向需要换位置的节点，通过顺序依次换位置实现。但是结果效率很低。
	优化：减少指针的修改次数。
	看了discussion 使用了指向节点的指针的指针，
	看了discussion，发现也可以使用recursive来实现。但是结果好像也不是很快。
*/

//version 1(7 ms)
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
    ListNode* swapPairs(ListNode* head) {
        ListNode new_head(-1);
        new_head.next = head;
        ListNode* first = &new_head;
        ListNode* third = &new_head;
        ListNode* second = &new_head;
        
        while(first->next!=NULL&&first->next->next!=NULL){
            second = first->next;
            third = second->next;
            second->next = third->next;
            first->next = third;
            third->next = second;
            first = first->next->next;
        }
        
        return new_head.next;
    }
};

//version 2(4 ms)
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode new_head(-1);
        new_head.next = head;
        ListNode* first = &new_head;
        ListNode* temp = &new_head;
        
        while(first->next!=NULL&&first->next->next!=NULL){
            temp = first->next->next;
            first->next->next = temp->next;
            temp->next = first->next;
            first->next = temp;
            first = first->next->next;
        }
        
        return new_head.next;
    }
};

//version 3(5 ms)
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode** pp=&head;
        //pp = &head;
        ListNode *first, *second;
        while((first = *pp) && (second = first->next)){
            first->next = second->next;
            second->next = first;
            *pp = second;
            pp = &(first->next);
        }
        return head;
    }
};

//version 4(5 ms)
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        
        ListNode *new_head = head->next;
        head->next = swapPairs(new_head->next);
        new_head->next = head;
        return new_head;
    }
};