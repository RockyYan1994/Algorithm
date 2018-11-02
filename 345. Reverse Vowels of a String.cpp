/*

*/

//version 1(12 ms)
class Solution {
public:
    string reverseVowels(string s) {
        int i=0, j=s.size()-1;
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        while (i < j) {
            while (i<j && vowels.find(tolower(s[i])) == vowels.end()) i++;
            while (i<j && vowels.find(tolower(s[j])) == vowels.end()) j--;
            if (i < j) swap(s[i++], s[j--]);
        }
        return s;
    }
};