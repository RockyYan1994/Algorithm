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
    public boolean findTarget(TreeNode root, int k) {
        Set<Integer> set = new HashSet();
        return preOrder(root, set, k);
    }
    
    private boolean preOrder(TreeNode root, Set<Integer> set, int k) {
        if (root == null) return false;
        if (set.contains(root.val)) return true;
        set.add(k - root.val);
        return preOrder(root.left, set, k) || preOrder(root.right, set, k);        
    }
}