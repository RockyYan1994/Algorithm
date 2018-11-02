/*
	方法一：单独针对相等情况进行判断。
*/

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        if (word1 == word2) {
            int last = words.size();
            int shortest = INT_MAX;
            for (int i=0;i<words.size();i++) {
                if (words[i] == word1) {
                    shortest = min (shortest, abs(i-last));
                    last = i;
                }                
            }
            return shortest;
        }
        int j = words.size() - 1, k = words.size() + words.size();
        int shortest = INT_MAX;
        for (int i=0; i<words.size();i++) {
            if (words[i] == word1) j = i;
            else if (words[i] == word2) k = i;
            shortest = min(shortest, abs(j-k));
        }
        return shortest;
    }
};