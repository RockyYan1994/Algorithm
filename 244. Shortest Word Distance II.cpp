/*

*/

//version 1(24 ms)
class WordDistance {
    unordered_map<string, vector<int>> um;
public:
    WordDistance(vector<string> words) {
        for (int i=0; i<words.size();i++) {
            um[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int shortest = INT_MAX;
        for (auto idx1 : um[word1]) {
            for (auto idx2 : um[word2]) {
                shortest = min (shortest, abs(idx1 - idx2));
            }
        }
        return shortest;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */