/*

*/

//version 1()
class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<string> res;
        if (s.empty()) return res;
        unordered_map<char, int> um;
        int odd = 0;
        for (char ch : s) {
            um[ch]++;
        }        
        string half;
        char mid;
        for (auto pair : um) {
            int cnt = pair.second;
            if (cnt % 2 == 1) {
                odd++;
                mid = pair.first;
            }
            if (odd > 1) return res;
            half += string(cnt/2, pair.first);
        }
        
        res = permutations(half);
        for (int i=0; i<res.size(); i++) {            
            string temp = res[i];
            reverse(res[i].begin(), res[i].end());
            if (odd == 1) res[i] = temp + string(1, mid) + res[i];
            else res[i] = temp + res[i];
        }
        return res;
    }
    
    vector<string> permutations(string s) {
        vector<string> res;
        string old(s);
        do {
            next_permutation(s.begin(), s.end());
            res.push_back(s);
        } while (s != old);
        return res;
    }
};