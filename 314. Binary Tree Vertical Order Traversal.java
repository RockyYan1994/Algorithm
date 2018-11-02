/*
	方法一：通过BFS实现，由于层数不用统计，但是需要统计col的计数，因此可以通过使用一个Queue来记录col实现。
	方法二：通过HashMap实现，用两个变量记录最左边和最右边的col值，来遍历Map。
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
    
    public List<List<Integer>> verticalOrder(TreeNode root) {
        Map<Integer, List<Integer>> M = new TreeMap<>();
        helper(root, M);
        List<List<Integer>> res = new ArrayList<>();
        for (Map.Entry<Integer, List<Integer>> pair : M.entrySet()) {
            res.add(pair.getValue());
        }
        return res;
    }
    
    private void helper(TreeNode root, Map<Integer, List<Integer>> M) {
        if (root == null) return;        
        Queue<TreeNode> Q = new LinkedList<>();
        Queue<Integer> CQ = new LinkedList<>();        
        Q.add(root);    
        CQ.add(0);
        while (!Q.isEmpty()) {
            int col = CQ.poll();
            if (!M.containsKey(col)) {
                M.put(col, new ArrayList<>());
            }
            TreeNode cur = Q.poll();
            M.get(col).add(cur.val);
            
            if (cur.left != null) {
                Q.add(cur.left);
                CQ.add(col-1);
            }
            if (cur.right != null) {
                Q.add(cur.right);
                CQ.add(col+1);
            }
        }        
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
    
    public List<List<Integer>> verticalOrder(TreeNode root) {             
        Map<Integer, List<Integer>> M = new HashMap<>();
        if (root == null) return new ArrayList<>(); 
        int[] border = new int[2];
        helper(root, M, border);
        List<List<Integer>> res = new ArrayList<>();        
        for (int i=border[0]; i<=border[1]; i++) {
            res.add(M.get(i));
        }
        return res;
    }
    
    private void helper(TreeNode root, Map<Integer, List<Integer>> M, int[] border) {          
        Queue<TreeNode> Q = new LinkedList<>();
        Queue<Integer> CQ = new LinkedList<>();        
        Q.add(root);    
        CQ.add(0);
        while (!Q.isEmpty()) {
            int col = CQ.poll();
            if (!M.containsKey(col)) {
                M.put(col, new ArrayList<>());
            }
            TreeNode cur = Q.poll();
            M.get(col).add(cur.val);
            
            if (cur.left != null) {
                Q.add(cur.left);
                CQ.add(col-1);
                border[0] = Math.min(border[0], col-1);
            }
            if (cur.right != null) {
                Q.add(cur.right);
                CQ.add(col+1);
                border[1] = Math.max(border[1], col+1);
            }
        }        
    }
}