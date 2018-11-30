/*

*/

//version 1(14 ms)
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
    public String tree2str(TreeNode t) {
        if (t == null) return "";
        return preOrder(t);
    }
    
    private String preOrder(TreeNode cur) {
        StringBuilder sb = new StringBuilder();
        sb.append(cur.val);                
        if (cur.left != null) {
            sb.append('(');    
            sb.append(preOrder(cur.left));
            sb.append(')');
        }                
        if (cur.right != null) {
            if (cur.left == null) {
                sb.append("()");
            }
            sb.append('(');
            sb.append(preOrder(cur.right));
            sb.append(')');
        }        
        return sb.toString();
    } 
}