/*

*/

//version 1()
/*
// Definition for a Node.
class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;

    public Node() {}

    public Node(int _val,Node _prev,Node _next,Node _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
    public Node flatten(Node head) {
        if (head == null) return null;
        Stack<Node> stack = new Stack();
        Node cur = head;
        while (true) {
            if (cur.next == null && cur.child == null && stack.isEmpty()) {
                break;
            }             
            if (cur.child != null) {
                stack.push(cur.next);
                cur.next = cur.child;
                cur.child = null;
                cur.next.prev = cur;                
                cur = cur.next;
                continue;
            }
            if (cur.next == null) {                
                Node next = stack.pop();
                if (next == null) {
                    cur.next = null;
                    continue;
                }
                cur.next = next;
                next.prev = cur;
                cur = next;                
                continue;
            }
            cur = cur.next;
        }
        return head;
    }
}