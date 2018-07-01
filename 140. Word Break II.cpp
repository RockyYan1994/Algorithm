/*

*/

//version 1(15 ms)
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> us(wordDict.begin(),wordDict.end());
        return wordBreak(s,us);
    }
    vector<string> wordBreak(string s, unordered_set<string> wordDict){
        if(m.count(s)) return m[s];
        vector<string> results;
        if( wordDict.count(s) ) results.push_back(s);
            
        for(int i=1;i<s.size();++i){
            string word=s.substr(i);
            if(wordDict.count(word)){
                string rem=s.substr(0,i);
                vector<string> prev=combine(word,wordBreak(rem,wordDict));
                results.insert(results.end(),prev.begin(), prev.end());
            }
        }
        m[s]=results; //memorize
        return results;
    }
private:
    unordered_map<string,vector<string> > m;
    vector<string> combine(string word, vector<string> pre){
        for(int i=0;i<pre.size();i++){
            pre[i] += ' ' + word;
        }
        return pre;
    }
};