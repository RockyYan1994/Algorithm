/*

*/
//version 1(8 ms)
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
    
    private int max;
    
    public int longestUnivaluePath(TreeNode root) {
        if (root == null) return 0;
        max = 0;
        helper(root);
        return max;
    }
    
    private int helper(TreeNode root) {
        int res = 0, left = 0, right = 0;
        if (root.left != null) {
            left = helper(root.left);
            left = root.val == root.left.val ? left + 1 : 0;            
        } 
        
        if (root.right != null) {
            right = helper(root.right);
            right =  root.val == root.right.val ? right + 1 : 0;
        }
        max = Math.max(max, left + right);
        return Math.max(left, right);
    }
}