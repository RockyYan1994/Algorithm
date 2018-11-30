/*

*/

//version 1(3 ms)
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
    public TreeNode trimBST(TreeNode root, int L, int R) {
        return trimHelper(root, L, R);
    }
    
    private TreeNode trimHelper(TreeNode root, int L, int R) {
        if (root == null) return null;
        if (root.val < L) {
            return trimHelper(root.right, L, R);
        } else if (root.val > R) {
            return trimHelper(root.left, L, R);
        } else {
            root.left = trimHelper(root.left, L, R);
            root.right = trimHelper(root.right, L, R);
        }
        return root;
    }
}