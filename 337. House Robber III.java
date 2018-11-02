/*
	方法一：采用DP，用一个hashmap来保存之前已经存在的值，避免重复。
	方法二：也是采用dp，优化空间复杂度。在使用的时候，通过返回一个数组来表明是否包含了下面的一个元素。
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
    public int rob(TreeNode root) {
        Map<TreeNode, Integer> map = new HashMap<>();
        return robHelper(root, map);        
    }
    
    private int robHelper(TreeNode root, Map<TreeNode, Integer> map) {
        if (root == null) return 0;
        if (map.containsKey(root)) return map.get(root);
        int val = 0;
        
        if (root.left != null) {
            val += robHelper(root.left.left, map) + robHelper(root.left.right, map);
        }
        if (root.right != null) {
            val += robHelper(root.right.left, map) + robHelper(root.right.right, map);
        }
        val =  Math.max(val + root.val, robHelper(root.left, map) + robHelper(root.right, map));
        map.put(root, val);
        return val;
    }
}

//version 2(1 ms)
class Solution {
    public int rob(TreeNode root) {        
        int[] res = robHelper(root);
        return Math.max(res[0], res[1]);
    }
    
    private int[] robHelper(TreeNode root) {
        if (root == null) return new int[2];
        
        int[] left = robHelper(root.left);
        int[] right = robHelper(root.right);
        int[] res = new int[2];
        
        res[0] = Math.max(left[0], left[1]) + Math.max(right[0], right[1]);
        res[1] = left[0]+right[0]+root.val;
        return res;
    }
}