/*

*/

//version 1(3 ms)
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode oddEvenList(ListNode head) {
        ListNode odd = new ListNode(1), even = new ListNode(2);
        ListNode op = odd, ep = even;
        int i = 1;
        while (head != null) {
            if (i % 2 == 0) {
                ep.next = head;
                ep = ep.next;                
            } else {
                op.next = head;
                op = op.next;                
            }
            head = head.next;
            i++;
        }
        ep.next = null;
        op.next = even.next;
        return odd.next;
    }
}