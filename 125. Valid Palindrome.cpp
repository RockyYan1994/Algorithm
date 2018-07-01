/*
	主要考虑对string的处理，查看discussion后发现可以采用函数isalnum判断是否为数字或者字母，采用tolower或者toupper来处理大小写问题。
*/

//version 1(10 ms)
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        int i = 0, j = s.size()-1;
        while(i < j){
            if(isalnum(s[i]) == false && i<j) i++;
            else if(isalnum(s[j]) == false && i<j) j--;
            else if(tolower(s[i]) != tolower(s[j])) return false;
            else{
                i++;
                j--;
            }
        }
        return true;
    }
};

//version 2(12 ms)
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        int i = 0, j = s.size()-1;
        while(i < j){
            if(isalnum(s[i]) == false) i++;
            else if(isalnum(s[j]) == false) j--;
            else if(tolower(s[i++]) != tolower(s[j--])) return false;
        }
        return true;
    }
};