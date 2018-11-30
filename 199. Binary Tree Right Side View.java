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
    public List<Integer> rightSideView(TreeNode root) {
        if (root == null) return new ArrayList();
        List<Integer> res = new ArrayList<>();
        Queue<TreeNode> Q = new LinkedList<>();        
        Q.add(root);
        while (!Q.isEmpty()) {
            int size = Q.size();
            for (int i = 0; i < size; i++) {
                TreeNode cur = Q.poll();
                if (i == 0) {
                    res.add(cur.val);                    
                }
                if (cur.right != null) Q.add(cur.right);
                if (cur.left != null) Q.add(cur.left);
            }
        }
        return res;
    }
}