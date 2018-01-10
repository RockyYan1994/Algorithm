class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t i=0,j=0;
        int maxLen = 0;

        while(true){
            if(j==s.length()) break;
            size_t found = s.find_first_of(s[j],i);
            if(found<j){
                i = found+1;
            }
            if((j-i+1)>maxLen) maxLen = j-i+1;

            j++;
        }
        return maxLen;
    }
};