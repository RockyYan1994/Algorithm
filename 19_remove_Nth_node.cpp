/*
	first
	首先想到使用一个count来计算和尾部的距离，如果距离==n 就把一个标记指针后移，通过一个遍历指针cur 和一个标记指针point指向被删除的
	元素前一个位置，当遍历到结尾的时候，利用 point->next = point->next->next 来实现删除。

	参考了discussion之后发现可以采用一个slow和一个fast，同时添加一个新的头部指针（指向head），先让fast后移n次，然后让slow和fast同时后移。

	Tips：注意在进行链表操作的时候，通常使用一个新的头部指针会让操作更简单。

	好像直接用指针 ListNode* pot = head 进行操作不能实现。
*/

//verison 1(8 ms)
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
    ListNode *removeNthFromEnd(ListNode *head, int n) 
    {
        if (!head)
            return nullptr;

        ListNode new_head(-1);
        new_head.next = head;

        ListNode *slow = &new_head, *fast = &new_head;
        int count=0;

        while (fast->next!=NULL) 
        {
            if(count>=n){
                slow = slow->next;
            }
            fast = fast->next;
            ++count;
        }

        slow->next = slow->next->next;

        return new_head.next;
    }
};

//version 2 (12 ms)
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
    ListNode *removeNthFromEnd(ListNode *head, int n) 
    {
        
        ListNode new_head(-1);
        new_head.next = head;
        ListNode* cur = &new_head;
        head = &new_head;
        
        while(n-- > 0) cur = cur->next;
        
        while(cur->next!=NULL){
            cur = cur->next;
            head = head->next;
        }
        
        head->next = head->next->next;
        
        return new_head.next;
    }
};