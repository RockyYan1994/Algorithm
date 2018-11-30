/*

*/

//version 1(4 ms)
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
    public TreeNode deleteNode(TreeNode root, int key) {
        return helper(root, key);
    }
    
    private TreeNode helper(TreeNode root, int key) {
        if (root == null) return null;
        if (root.val > key) {
            root.left = helper(root.left, key);
        } else if (root.val < key) {
            root.right = helper(root.right, key);
        } else {
            if (root.left ==null) {
                return root.right;
            } else if (root.right == null) {
                return root.left;
            } else {
                TreeNode next = root.right;
                while (next.left != null) {
                    next = next.left;
                }
                root.val = next.val;
                root.right = helper(root.right, root.val);
            }
        }
        return root;
    }
}