/*

*/

//version 1()
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, vector<int>> pattern_map;
        unordered_map<string, int> words_map;
        vector<string> words = collector(str);
        if (words.size() != pattern.size(

        	//version 2()
        	)) return false;
        
        for (int i=0; i<pattern.size(); i++) {
            pattern_map[pattern[i]].push_back(i);
            words_map[words[i]] = 0;
        }
        
        if (pattern_map.size() != words_map.size()) return false;
        
        for (auto pair : pattern_map) {
            vector<int> same_pattern = pair.second;
            for (int i=1; i<same_pattern.size(); i++) {
                if (words[same_pattern[i]] != words[same_pattern[i-1]]) return false;
            }
        }
        
        return true;
    }
    
    vector<string> collector(string str) {
        vector<string> res;
        int j = 0;
        for (int i=0; i<str.size(); i++) {
            if (str[i] == ' ') continue;
            j = i;
            while (j < str.size() && str[j] != ' ') j++;
            res.push_back(str.substr(i, j-i));
            i = j;
        }
        return res;
    }
};

//version 2()
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int i=0;
        unordered_map<char, int> p2i;
        unordered_map<string, int> w2i;
        istringstream ss(str);
        string word;
        while(ss >> word) {
            if (i!=0 && p2i[pattern[i]] != w2i[word]) return false;
            p2i[pattern[i]] = w2i[word] = i+1;
            i++;
        }
        return i == pattern.size();
    }
};