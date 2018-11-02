/*
	方法一：采用无序map记录一个string，然后判断。
*/

//version 1(12 ms)
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> um;
        for (auto ch : s) um[ch]++;
        for (auto ch : t) um[ch]--;
        for (auto &p : um) {
            if (p.second != 0) return false;
        }
        return true;
    }
};

//version 2(8 ms)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> um;
        for (int i=0; i<s.size(); i++) {
            um[s[i]]++;
            um[t[i]]--;
        }
        for (auto &p : um) {
            if (p.second != 0) return false;
        }
        return true;
    }
};

//version 3(4 ms)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> alpha(26, 0);
        for (int i=0;i<s.size();i++) {
            alpha[s[i]-'a']++;
            alpha[t[i]-'a']--;
        }
        for (auto num : alpha) {
            if (num) return false;
        }
        return true;
    }
};