/*
    first
    首先想到使用队列（错的。），然后想到是使用vector<char>来实现，如果出现反括号就和vector中最后一个比较，如果vector==0或者不为对应的就返回
    false，然后pop_back vector，如果最后vecotr长度不为0，则返回false。

    优化，采用别的数据结构，采用stack，实现1ms优化。。
*/
//version 1(4 ms)
class Solution {
public:
    bool isValid(string s) {
        vector<char> vec;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
                vec.push_back(s[i]);
            }
            else if(s[i]==')'){
                if(vec.size()==0||vec[vec.size()-1]!='(') return false;
                vec.pop_back();
            }
            else if(s[i]=='}'){
                if(vec.size()==0||vec[vec.size()-1]!='{') return false;
                vec.pop_back();
            }
            else if(s[i]==']'){
                if(vec.size()==0||vec[vec.size()-1]!='[') return false;
                vec.pop_back();
            }
            else return false;
        }
        if(vec.size()!=0) return false;
        return true;
    }
};
//version 2(3 ms)
class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
                sta.push(s[i]);
            }
            else if(s[i]==')'){
                if(sta.empty()||sta.top()!='(') return false;
                sta.pop();
            }
            else if(s[i]=='}'){
                if(sta.empty()||sta.top()!='{') return false;
                sta.pop();
            }
            else if(s[i]==']'){
                if(sta.empty()||sta.top()!='[') return false;
                sta.pop();
            }
            else return false;
        }
        return sta.empty();
    }
};

//version 3(3 ms)
class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        for(int i=0;i<s.size();i++){
            switch (s[i]){
                case '(':
                case '{':
                case '[':{
                    sta.push(s[i]);
                    break;
                }
                case ')':   
                    if(sta.empty()||sta.top()!='(') return false;
                    sta.pop();
                    break;
                case '}':
                    if(sta.empty()||sta.top()!='{') return false;
                    sta.pop();
                    break;
                case ']':
                    if(sta.empty()||sta.top()!='[') return false;
                    sta.pop();
                    break;
                default: return false;
            }
        }
        return sta.empty();
    }
};