/*

*/

//version 1()
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        StringBuilder a = new StringBuilder(), b = new StringBuilder();
        while (l1 != null) {
            a.append(l1.val);
            l1 = l1.next;
        }
        while (l2 != null) {
            b.append(l2.val);
            l2 = l2.next;
        }
        String res = strAdd(a, b); 
        //System.out.println(res);
        ListNode head = new ListNode(-1);
        int i = 0;
        while (i < res.length()) {
            ListNode cur = new ListNode(res.charAt(i) - '0');            
            cur.next = head.next;
            head.next = cur;
            i++;
        }
        if (head.next == null) {
            return new ListNode(0);
        }
        return head.next;
    }
    
    private String strAdd(StringBuilder a, StringBuilder b) {
        a = a.reverse();
        b = b.reverse();
        StringBuilder res = new StringBuilder();
        int off = 0, i = 0, j = 0;
        while (i < a.length() || j < b.length() || off == 1) {
            //System.out.println(i + ", " + j);
            int cur = 0;
            cur += i < a.length() ? a.charAt(i) - '0' : 0;
            cur += j < b.length() ? b.charAt(j) - '0' : 0;
            cur += off;
            off = cur / 10;
            res.append(cur % 10);
            i++;
            j++;
        }
        return res.toString();
    }
}