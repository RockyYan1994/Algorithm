/*
	方法一：https://kingsfish.github.io/2017/12/15/Leetcode-421-Maximum-XOR-of-Two-Numbers-in-an-Array/
	方法二：采用Trie树，先通过一次遍历构建树。然后通过遍历每一个数字，查找每一个位上的bit的异或节点是否存在，如果存在说明这一位能够作为结果加到tmp，最后
		计算一个max = Math.max(tmp, max);
*/

//version 1(58 ms)
class Solution {
    public int findMaximumXOR(int[] nums) {
        int mask = 0, max = 0;
        for (int i=31; i>=0; i--) {
            Set<Integer> S = new HashSet<Integer>();
            mask = mask | (1 << i);
            for (int num : nums) {
                S.add(num & mask);
            }
            int tmp = max | (1 << i);
            for (int num : S) {
                if (S.contains(tmp ^ num)) {
                    max = tmp;
                    break;
                }
            }
        }
        return max;
    }
}

//version 2(47 ms)
class Solution {
    public int findMaximumXOR(int[] nums) {
        if (nums.length == 0) return 0;
        Trie root = new Trie();
        for (int num : nums) {
            Trie cur = root;
            for (int j=31; j>=0; j--) {
                int bit = 1 & (num >>> j);
                if (cur.children[bit] == null) {
                    cur.children[bit] = new Trie();
                }
                cur = cur.children[bit];
            }
        }
        int max = 0;
        for (int num : nums) {
            Trie cur = root;
            int tmp = 0;
            for (int i=31; i>=0; i--) {
                int bit = 1 & (num >>> i);
                if (cur.children[bit ^ 1] != null) {
                    tmp |= (1 << i);
                    cur = cur.children[bit ^ 1];
                } else {
                    cur = cur.children[bit];
                }
            }
            max = Math.max(max, tmp);
        }
        return max;
    }
    
    class Trie {
        Trie[] children;
        public Trie() {
            children = new Trie[2];
        }
    }
}