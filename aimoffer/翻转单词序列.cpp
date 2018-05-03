/*
例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。
可以采用先翻转句子，再翻转每个单词的方法。
*/

class Solution {
public:
    string ReverseSentence(string str) {
        if(str.empty()) return str; 
        swapstr(str,0,str.size()-1);
        int l=0,r=0,i=0;
        while(i<str.size()){
            while(i<str.size() && str[i]==' ') i++;
            l = r = i;
            while(i<str.size() && str[i]!=' ') i++;
            r = i;
            swapstr(str,l,r-1);
        }
        return str;
    }
    void swapstr(string& str,int l,int r){
        while(l<r){
            swap(str[l],str[r]);
            l++;r--;
        }
    }
};