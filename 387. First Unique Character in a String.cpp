/*
	方法一：用一个数组记住每个字符的位置，如果重复出现就改为s.size。
*/

//version 1(24 ms)
class Solution {
public:
    int firstUniqChar(string s) {
        if (s.empty()) return -1;
        vector<int> counts(26, -1);
        for (int i=0; i<s.size(); i++) {
            int pos = s[i]-'a';
            if (counts[pos] == -1) counts[pos] = i;
            else counts[pos] = s.size();
        }
        int res = s.size();
        for (auto pos : counts) {
            if (pos >= 0) res = min(res, pos);
        }
        return res == s.size() ? -1 : res;
    }
};