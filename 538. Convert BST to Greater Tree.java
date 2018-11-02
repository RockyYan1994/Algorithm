/*
	方法一：采用后续遍历，但是要注意如果出现左右不存在的情况，就要跳过。不然会出现重复计算的情况。
*/

//version 1(9 ms)
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
    public TreeNode convertBST(TreeNode root) {
        postTraverse(root, 0);
        return root;
    }
    
    public int postTraverse(TreeNode root, int sum) {
        if (root == null) return 0;
        if (root.right != null) sum = postTraverse(root.right, sum);
        sum += root.val;
        root.val = sum;
        if (root.left != null) return postTraverse(root.left, sum);        
        return sum;
    }
}