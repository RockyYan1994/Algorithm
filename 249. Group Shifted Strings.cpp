/*

*/

//version 1(0 ms) 
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> res;
        map<string, vector<string>> patterns;
        for (auto s : strings) {
            string pattern = constructPattern(s);
            patterns[pattern].push_back(s);
        }
        for (auto arr : patterns) {
            res.push_back(arr.second);
        }
        return res;
    }
    
    string constructPattern(string s) {
        string res = "0";        
        for (int i=1; i<s.size(); i++) {
            int diff = s[i] - s[i-1];
            res += diff > 0 ? diff : diff + 26;
        }
        return res;
    }
    
};