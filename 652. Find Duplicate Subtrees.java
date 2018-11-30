/*

*/

//version 1(23 ms)
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
    
    private Map<String, Integer> M;
    
    private List<TreeNode> res;
    
    public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
        M = new HashMap();
        res = new ArrayList();
        
        //System.out.println(inorder(root));
        inorder(root);
        return res;
    }
    
    private String inorder(TreeNode root) {
        if (root == null) return "#";
        String s = root.val + "," + inorder(root.left) + "," + inorder(root.right);
        M.put(s, M.getOrDefault(s, 0) + 1);
        if (M.get(s) == 2) {
            res.add(root);
        }
        return s;
    }
}