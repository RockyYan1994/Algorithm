/*
	方法一：主要采用计算左右行高，然后比较。
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
    private int cnt;
    public int diameterOfBinaryTree(TreeNode root) {
        cnt = 0;
        deepth(root);
        return cnt;
    }
    
    private int deepth(TreeNode root) {
        if (root == null) return 0;
        int l = deepth(root.left);
        int r = deepth(root.right);
        cnt = Math.max(l+r, cnt);
        return 1 + Math.max(l, r);
    }
}