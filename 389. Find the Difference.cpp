/*
	方法一：用map统计
	方法二：异或
*/

//version 1(4 ms)
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> ch2cnt;
        for (auto ch : s) {
            ch2cnt[ch]++;            
        }
        for (auto ch : t) {
            ch2cnt[ch]--;
        }
        for (auto pair : ch2cnt) {
            if (pair.second != 0) return pair.first;
        }
        return ' ';
    }
};

//version 2(0 ms)
class Solution {
public:
    char findTheDifference(string s, string t) {
        char ch = t[t.size()-1];
        for (int i=0; i<s.size(); i++) {
            ch ^= s[i];
            ch ^= t[i];
        }
        return ch;
    }
};