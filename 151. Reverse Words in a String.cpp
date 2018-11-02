/*
题目描述的十分不清楚，整体思路就是用i往后遍历，j是记录当前应该放置的点，每次j记录完一个单词，先进行reverse，
最后在大循环之后，resize除掉后面的空格，然后整体reverse。
*/

class Solution {
public:
    void reverseWords(string &s) {
        int i =0, j = 0;
        int len = s.size();
        bool hasWord = false;
        while(i<len) {
            while(i<len && s[i] == ' ') i++;
            if(hasWord&&i<len) s[j++] = ' ';
            int l = j;
            while(i<len && s[i] != ' ') {s[j++] = s[i++]; hasWord = true;}
            rangeSwap(s,l,j-1);
        }
        s.resize(j);
        rangeSwap(s,0,s.size()-1);
    }
    void rangeSwap(string &s, int start, int end) {
        while(start < end) {
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
    }
};