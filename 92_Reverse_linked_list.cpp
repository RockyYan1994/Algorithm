/*
    first
*/


/*
  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode **start = &head;
        ListNode *temp;
        int count = 0;
        for(int i=1;i<m;i++){
            start = &((*start)->next);
        }
        temp = *start;
        for(int i=m;i<=n;i++){
            start = &(temp->next);
            temp->next = (*start)->next;
            (*start)->next = temp;
            temp = temp->next;
        }
        return head;
    }
};

//version 2(from discussion)
ListNode* reverseBetween(ListNode *head, int m, int n) {
    ListNode **a = &head, **b;
    for (;m--; n--)
        a = &(*(b=a))->next;
    for (;n--; swap(*b, *a))
        swap(*b, (*a)->next);
    return head;
}