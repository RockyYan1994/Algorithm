/*

*/

//version 1(6 ms)
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
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        return helper(nums, 0, nums.length - 1);
    }
    
    private TreeNode helper(int[] nums, int l, int r) {        
        if (l > r) return null;
        if (l == r) return new TreeNode(nums[l]);
        int maxIndex = l;
        for (int i = l+1; i <= r; i++) {
            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }
        //System.out.println(maxIndex);
        TreeNode cur = new TreeNode(nums[maxIndex]);
        cur.left = helper(nums, l, maxIndex - 1);
        cur.right = helper(nums, maxIndex + 1, r);
        return cur;
    }
}

//version 2(21 ms)
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
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        Stack<TreeNode> stack = new Stack<>();
        for (int num : nums) {
            TreeNode cur = new TreeNode(num);
            while (!stack.isEmpty() && stack.peek().val < num) {
                cur.left = stack.pop();
            }
            if (!stack.isEmpty()) {
                stack.peek().right = cur;            
            }
            stack.push(cur);
        }
        while (stack.size() > 1) {
            stack.pop();
        }
        return stack.pop();
    }
}