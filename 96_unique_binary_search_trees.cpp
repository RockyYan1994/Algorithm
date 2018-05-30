/*
*	解法参考了discussion中的第一个，采用DP的方法，首先用一个循环进行遍历，让每个节点都作为一次顶点，那么F(i,n) = G(i-1)*G(n-i)
*	也就是左边的可能种类乘以右边的可能种类。而G其实在元素个数相同的情况下，值时相同的，因为没有重复的元素。G(n)的意思就是n个元素的能组成多少个独立的BST。
*	reference: https://leetcode.com/problems/unique-binary-search-trees/discuss/31666/DP-Solution-in-6-lines-with-explanation.-F(i-n)-G(i-1)-*-G(n-i)
*/

//version 1(2ms)
class Solution {
public:
    int numTrees(int n) {
        vector<int> g(n+1,0);
        g[0] = g[1] = 1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                g[i] += g[j-1] * g[i-j];
            }
        }
        return g[n];
    }
};