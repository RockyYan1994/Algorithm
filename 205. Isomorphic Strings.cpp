/*
	通过两个256的数组（针对ASCII码）来实现。
*/

//version 1(8 ms)
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> m1(256,0), m2(256,0);
        for(int i=0;i<s.size();i++){
            if(m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i+1;
            m2[t[i]] = i+1;
        }
        return true;
    }
};