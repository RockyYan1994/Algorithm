/*

*/

//version 1()
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
    
    private int min = Integer.MAX_VALUE;
    private Integer prev = null;    
    
    public int getMinimumDifference(TreeNode root) {
        if (root == null) return min;
        getMinimumDifference(root.left);
        if (prev != null) {
            min = Math.min(min, root.val - prev);   
        }        
        prev = root.val;
        getMinimumDifference(root.right);
        return min;
    }    
}