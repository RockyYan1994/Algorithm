/*

*/

//version 1(47 ms)
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode increasingBST(TreeNode root) {
        Stack<TreeNode> s = new Stack();        
        TreeNode dummy = new TreeNode(0);
        TreeNode cur = root, tail = dummy;        
        while (!s.isEmpty() || cur != null) {
            if (cur != null) {
                s.push(cur);                
                cur = cur.left;
                continue;
            }
            cur = s.pop();
            tail.right = cur;
            tail = tail.right;            
            cur.left = null;                        
            cur = cur.right;
        }
        return dummy.right;
    }
}