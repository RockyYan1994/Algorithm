/*
	方法一：用map统计，只有一个为奇数则true。
	方法二：用set，出现过就remove。最后size == 1则true；
*/

//version 1(0 ms)
class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> um;
        for (auto ch : s) {
            um[ch]++;
        }
        
        int cnt = 0;
        for (auto pair : um) {
            if (pair.second%2 == 1) cnt++;
            if (cnt > 1) return false;
        }
        return true;
    }
};

//version 2(0 ms)
class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_set<char> us;
        for (auto ch : s ) {
            if (us.find(ch) != us.end()) us.erase(ch);
            else us.insert(ch);
        }
        return us.size()<=1;
    }
};