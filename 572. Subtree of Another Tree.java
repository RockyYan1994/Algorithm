/*

*/

//version 1(15 ms)
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
    public boolean isSubtree(TreeNode s, TreeNode t) {
        if (s == null && t == null) return true;
        if (s == null || t == null) return false;
        return helper(s, t) || isSubtree(s.left, t) || isSubtree(s.right, t);
    }
    
    private boolean helper(TreeNode s, TreeNode t) {
        if (s == null && t == null) return true;
        if (s == null || t == null) return false;
        return s.val == t.val && helper(s.left, t.left) && helper(s.right, t.right);
    }
}

//version 2(28 ms)
class Solution {
    public boolean isSubtree(TreeNode s, TreeNode t) {
        String preOrder_s = helper(s, false);
        String preOrder_t = helper(t, false);
        return preOrder_s.indexOf(preOrder_t) >= 0;
    }
    
    private String helper(TreeNode root, boolean left) {
        if (root == null) {
            if (left) {
                return "lnull";
            } else {
                return "rnull";
            }
        }
        return "#" + root.val + helper(root.left, true) + helper(root.right, false);
    }
}