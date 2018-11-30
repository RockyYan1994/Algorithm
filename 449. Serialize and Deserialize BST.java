/*

*/

//version 1(7 ms)
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if (root == null) return "";
        return root.val + "," + serialize(root.left) + serialize(root.right);
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if (data == null) return null;
        if ("".equals(data)) return null;
        TreeNode dummy = new TreeNode(0);
        helper(data.split(","), true, Integer.MIN_VALUE, Integer.MAX_VALUE, dummy, 0);
        return dummy.left;        
    }
    
    private int helper(String[] datas, boolean isLeft, int lower, int upper, TreeNode parent, int pos) {
        if (pos >= datas.length) return pos;
        int val = Integer.valueOf(datas[pos]);
        if (val < lower || val > upper) return pos - 1;
        TreeNode cur = new TreeNode(val);
        if (isLeft) {
            parent.left = cur;
        } else {
            parent.right = cur;
        }
        pos =  helper(datas, true, lower, val, cur, ++pos);
        pos =  helper(datas, false, val, upper, cur, ++pos);
        return pos;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));