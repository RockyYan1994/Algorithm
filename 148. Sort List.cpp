/*
	采用merge-sort的自底向上的方法来实现。
    version2 递归版
*/

//version 1(53 ms)
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
    ListNode* sortList(ListNode* head) {
        if(!head) return NULL;
        ListNode preHead(0);
        preHead.next = head;
        ListNode *left, *right, *tail, *cur = head;
        int n = 0;
        while(cur){
            n++;
            cur = cur -> next;
        }

        for(int size=1;size < n;size<<=1){
            cur = preHead.next;
            tail = &preHead;
            while(cur){
                left = cur;
                right = split(left,size);
                cur = split(right, size);
                tail = merge(left, right, tail);
            }
        }
        return preHead.next;
    }
private:
    ListNode* split(ListNode* head, int size){
        for(int i=1;i<size && head;i++) head = head -> next;
        if(!head) return NULL;
        
        ListNode* second = head -> next;
        head -> next = NULL;
        return second;
    }
    ListNode* merge(ListNode* l1,ListNode* l2, ListNode* head){
        ListNode* cur = head;
        while(l1 && l2){
            if(l1->val > l2->val){
                cur -> next = l2;
                cur = l2;
                l2 = l2 -> next;
            }else{
                cur -> next = l1;
                cur = l1;
                l1 = l1 -> next;
            }
        }
        cur -> next = l1 ? l1 : l2;
        while(cur -> next) cur = cur -> next;
        return cur;
    }
};

//version 2(56 ms)
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode *fast = head->next->next, *slow = head;
        while(fast && fast->next){
            slow = slow -> next;
            fast = fast->next->next;
        }
        ListNode* h2 = sortList(slow->next);
        slow -> next = NULL;
        return merge(sortList(head),h2);
    }
private:
    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode* newHead = new ListNode(-1);
        ListNode* cur = newHead;
        while(l1 && l2){
            if(l1->val < l2 -> val){
                cur -> next = l1;
                cur = cur -> next;
                l1 = l1 -> next;
            }else{
                cur -> next = l2;
                cur = cur -> next;
                l2 = l2 -> next;
            }
        }
        cur -> next = l1 ? l1 : l2;
        return newHead -> next;
    }
};