/*

*/

//version 1(0 ms)
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode first = new ListNode(0), second = new ListNode(0), cur = head, F = first, S = second;
        while (cur != null) {
            //System.out.println(cur.val);
            if (cur.val < x) {
                F.next = cur;              
                F = F.next;
            } else {
                S.next = cur;
                S = S.next;
            }
            cur = cur.next;
        }        
        S.next = null;
        F.next = second.next;
        return first.next;
    }
}