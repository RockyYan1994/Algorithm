/*	
	方法一：采用一个priorityQueue把每个list放入。
	方法二：divide and conquer，通过每次两两合并。
*/

//version 1(53 ms)
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        Queue<ListNode> pq = new PriorityQueue<ListNode>((a,b)->(a.val - b.val));
        for (ListNode node : lists) {
            if (node != null) {
                pq.add(node);      
            }            
        }
        ListNode head = new ListNode(-1);        
        ListNode cur = head;
        while (!pq.isEmpty()) {            
            cur.next = pq.poll();
            cur = cur.next;
            if (cur.next != null) pq.add(cur.next);
        }
        return head.next;
    }
}

//version 2(8 ms)
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists.length == 0) return null;
        int amount = lists.length;
        while (amount > 1) {
            int shift = (amount+1)/2;
            for (int i=0; i<amount; i++) {
                if (i+shift < amount) lists[i] = merge2Lists(lists[i], lists[i+shift]);
            }
            amount = shift;
        }
        return lists[0];
    }
    
    private ListNode merge2Lists(ListNode l1, ListNode l2) {
        ListNode head = new ListNode(-1);
        ListNode cur = head;
        while (l1 != null && l2 != null) {
            if (l1.val < l2.val) {
                cur.next = l1;
                l1 = l1.next;                
            } else {
                cur.next = l2;
                l2 = l2.next;                
            }
            cur = cur.next;
        }
        cur.next = l1 == null ? l2 : l1;
        return head.next;
    }
}