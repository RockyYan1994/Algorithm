/*
	方法一：每次将tail移动到第k个，然后不断将前面k-1个元素添加到后面。如果不足k和就退出。
	方法二：递归实现。from shpolsky
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
    public ListNode reverseKGroup(ListNode head, int k) {
        if (head == null || head.next == null || k < 2) return head;
        ListNode preHead = new ListNode(0);
        preHead.next = head;        
        ListNode tail = preHead, prev = preHead, temp;
        while (true) {
            int count = k;
            while (count > 0 && tail.next != null) {
                tail = tail.next;
                count--;
            }
            if (count != 0) break;
            head = prev.next;
            while (count++ < k-1) {                
                temp = prev.next;
                prev.next = temp.next;
                temp.next = tail.next;
                tail.next = temp;
            }
            tail = head;
            prev = head;
        }
        return preHead.next;
    }
}


//version 2(from shpolsky)
public ListNode reverseKGroup(ListNode head, int k) {
    ListNode curr = head;
    int count = 0;
    while (curr != null && count != k) { // find the k+1 node
        curr = curr.next;
        count++;
    }
    if (count == k) { // if k+1 node is found
        curr = reverseKGroup(curr, k); // reverse list with k+1 node as head
        // head - head-pointer to direct part, 
        // curr - head-pointer to reversed part;
        while (count-- > 0) { // reverse current k-group: 
            ListNode tmp = head.next; // tmp - next head in direct part
            head.next = curr; // preappending "direct" head to the reversed list 
            curr = head; // move head of reversed part to a new node
            head = tmp; // move "direct" head to the next node in direct part
        }
        head = curr;
    }
    return head;
}