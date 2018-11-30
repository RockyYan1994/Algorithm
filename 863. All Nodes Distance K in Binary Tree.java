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
    public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
        Map<TreeNode, TreeNode> parent = new HashMap();
        findParent(parent, root);
        List<Integer> res = new ArrayList();
        Set<TreeNode> visited = new HashSet();
        dfs(target, K, res, visited, parent);
        return res;
    }
    
    private void dfs(TreeNode root, int k, List<Integer> res, Set<TreeNode> visited, Map<TreeNode, TreeNode> parent) {
        if (root == null || visited.contains(root)) {
            return;
        }
        visited.add(root);
        if (k == 0) {
            res.add(root.val);
            return;
        }
        if (root.left != null) {
            dfs(root.left, k-1, res, visited, parent);
        }
        if (root.right != null) {
            dfs(root.right, k-1, res, visited, parent);
        }
        if (parent.get(root) != null) {
            dfs(parent.get(root), k-1, res, visited, parent);
        }
    }
    
    private void findParent(Map<TreeNode, TreeNode> parent, TreeNode root) {
        if (root == null) {
            return;
        }
        if (root.left != null) {
            parent.put(root.left, root);
            findParent(parent, root.left);
        }
        if (root.right != null) {
            parent.put(root.right, root);
            findParent(parent, root.right);
        }        
    }
})


//version 2(from BingleLove)
class Solution {
    
    Map<TreeNode, Integer> map = new HashMap<>();
        
    public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
        List<Integer> res = new LinkedList<>();
        find(root, target);
        dfs(root, target, K, map.get(root), res);
        return res;
    }
    
    // find target node first and store the distance in that path that we could use it later directly
    private int find(TreeNode root, TreeNode target) {
        if (root == null) return -1;
        if (root == target) {
            map.put(root, 0);
            return 0;
        }
        int left = find(root.left, target);
        if (left >= 0) {
            map.put(root, left + 1);
            return left + 1;
        }
	int right = find(root.right, target);
	if (right >= 0) {
            map.put(root, right + 1);
            return right + 1;
        }
        return -1;
    }
    
    private void dfs(TreeNode root, TreeNode target, int K, int length, List<Integer> res) {
        if (root == null) return;
        if (map.containsKey(root)) length = map.get(root);
        if (length == K) res.add(root.val);
        dfs(root.left, target, K, length + 1, res);
        dfs(root.right, target, K, length + 1, res);
    }
}