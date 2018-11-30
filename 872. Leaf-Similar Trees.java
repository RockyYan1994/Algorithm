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
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        List<Integer> l1 = new ArrayList(), l2 = new ArrayList();
        inorder(l1, root1);
        inorder(l2, root2);
        return l1.equals(l2);
    }
    
    private void inorder(List<Integer> leaves, TreeNode root) {
        if (root == null) return;
        if (root.left == null && root.right == null) {
            leaves.add(root.val);
        }
        inorder(leaves, root.left);
        inorder(leaves, root.right);
    }
}

//version 2(2 ms)
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
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        Stack<TreeNode> stack1 = new Stack(), stack2 = new Stack();
        stack1.push(root1);
        stack2.push(root2);
        while (!stack1.isEmpty() && !stack2.isEmpty()) {
            if (dfs(stack1) != dfs(stack2)) {
                return false;
            }
        }
        
        return stack1.isEmpty() && stack2.isEmpty();
    }

    private int dfs(Stack<TreeNode> stack) {
        while (!stack.isEmpty()) {
            TreeNode root = stack.pop();
            if (root.right != null) stack.push(root.right);
            if (root.left != null) stack.push(root.left);
            if (root.left == null && root.right == null) return root.val;
        }
        return -1;
    }
}