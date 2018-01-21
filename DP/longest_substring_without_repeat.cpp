/*
    first
    本题和最大值子数列的问题很像，主要问题在于如何查找重复的字符，思路一开始主要是通过两个size_t的位置变量来作为子序列的指针，通过每次增加一个然后搜索
    子序列来查看有无重复，如果有重复就将子序列头指针指向重复位置后一个，每次添加新的尾指针时，查看子序列有无重复。复杂度为 s.length()*find()复杂度

    优化思想:考虑到find的查找并非为最优化，可以考虑利用map来进行char的查找，通过每次查找到重复的字符更新开始位置。
*/
// version 1 (27 ms)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t i=0,j=0;
        int maxLen = 0;

        while(true){
            if(j==s.length()) break;
            size_t found = s.find_first_of(s[j],i);
            if(found<j){
                i = found+1;
            }
            if((j-i+1)>maxLen) maxLen = j-i+1;

            j++;
        }
        return maxLen;
    }
};