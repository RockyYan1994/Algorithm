/*
	方法一：分别记录每个词的所有位置，最后通过所有位置差判断，但是效率非常低。
	方法二：根据距离特性，每次更新重新计算即可。
*/


//version 1(20 ms)
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        unordered_map<string, vector<int>> um;
        for (int i=0; i<words.size();i++) {
            um[words[i]].push_back(i);
        }
        vector<int> idx1 = um[word1];
        vector<int> idx2 = um[word2];
        int shortest = INT_MAX;
        for (auto idx1 : um[word1]) {
            for (auto idx2 : um[word2]) {
                shortest = min (shortest, abs(idx1 - idx2));
            }
        }
        return shortest;
    }
};

//version 2(8 ms)
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
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