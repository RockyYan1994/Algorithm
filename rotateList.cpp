/*
	first
	首先想到只使用一次
*/

//version 1 
// this version can't fit when k larger than list length
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL) return head;
        int count = 1;
        ListNode* cur = head;
        ListNode* ret = head;
        ListNode* rear = head;
        
        //find the new head position
        while(cur->next != NULL){      
            cur = cur->next;
            if(count == k-1){
                new_rear = ret;
                ret = ret->next;
            }
            else{
                count++;
            }
        }
        //if ret is not modified
        if(new_rear == ret) return ret;
        
        cur->next = head;
        new_rear->next = NULL;
        return ret;
        
    }
};

//version 2 (12 ms)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL) return head;
        int count = 1;
        ListNode* cur = head;
        ListNode* ret = head;
        ListNode* rear = head;
        ListNode* new_rear = NULL;
        
        while(cur->next!=NULL){
            count++;
            cur = cur->next;
        }
        rear = cur;
        k = k%count;
        if(k == 0) return head;
        cur = head;
        for(int i=0;i<count-k;i++){
            new_rear = cur;
            cur = cur->next;
        }
        
        ret = cur;
        if(new_rear!=NULL) {
            new_rear->next = NULL;
            rear->next = head;
        }
        return ret; 
    }
};

//version 3 (9 ms)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL) return head;
        if(k==0) return head;
        int count = 1;
        ListNode* cur = head;
        ListNode* ret = head;
        
        while(cur->next!=NULL){
            count++;
            cur = cur->next;
        }
        k %= count;
        if(k == 0) return head;
        cur->next = head;
        cur = head;
        for(int i=0;i<count-k-1;i++){
            cur = cur->next;
        }

        ret = cur->next;
        cur->next = NULL;
        return ret;
    }
};