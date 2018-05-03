/*
在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置
想到使用map的方式来实现，也可以unordermap，或者自己实现一个map，但是要考虑大小写。
*/

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        map<char,int> m;
        for(auto c : str){
            m[c]++;
        }
        for(int i=0;i<str.size();i++){
            if(m[str[i]] == 1) return i;
        }
        return -1;
    }
};