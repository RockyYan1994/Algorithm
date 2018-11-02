/*

*/

//version 1(5 ms)
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
    public int sumOfLeftLeaves(TreeNode root) {
        Stack<TreeNode> S = new Stack<>();
        TreeNode cur = root;
        int res = 0;
        while (!S.empty() || cur != null) {
            if (cur != null) {
                S.push(cur);
                cur = cur.left;
                continue;
            }
            cur = S.pop();
            TreeNode parent = S.empty() ? null : S.peek();
            if (parent != null && parent.left == cur && cur.left == null && cur.right == null) {
                res += cur.val;
            }
            cur = cur.right;
        }
        return res;
    }
}