/*
    first;
    When handle List, must consider carefully about the end condition.
    处理的时候需要注意操作List需要使用 list->next 而不能直接使用 list。 防止直接定位到NULL。
    当处理两个或以上的list的时候，尽量不要在原有的list上面操作，避免结束条件的不清晰。
    可以多尝试使用三元运算符 Condition?A:B

*/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sign = 0;
        ListNode* ret = l1;
        while((l1->next!=NULL)&&(l2->next!=NULL)){
            l1->val = (l1->val + l2->val + sign);
            sign = l1->val / 10;
            l1->val = l1->val % 10;
            l1 = l1->next;
            l2 = l2->next;
            
        }
        if(l2->next!=NULL){
            l1->next = l2->next;
        }
        l1->val = (l1->val + l2->val + sign);
        sign = l1->val / 10;
        l1->val = l1->val % 10;
        while(l1->next!=NULL){
            l1 = l1->next;
            l1->val = (l1->val+sign) ;
            sign = l1->val / 10;
            l1->val = l1->val % 10;
            if(sign==0)break;
        }
        
        if(sign==1) {
            l1->next = new ListNode(1);
        }
        
        return ret;
    }
};