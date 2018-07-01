/*
	参考了jianchao.li.fighter的解法，
*/

//version 1(34 ms)
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int dist = 2;
        unordered_set<string> wordDict;
        // unordered_set<string> wordDict(wordList.begin(),wordList.end());
        for(auto s : wordList){
            wordDict.insert(s);
        }
        if(wordDict.find(endWord)==wordDict.end()) return 0;
        unordered_set<string> head, tail, *phead, *ptail;
        head.insert(beginWord);
        tail.insert(endWord);
        while(!head.empty() && !tail.empty())
        {
            if(head.size() < tail.size()){
                phead = &head;
                ptail = &tail;
            }else{
                phead = &tail;
                ptail = &head;
            }
            unordered_set<string> temp;
            for(auto itr = phead->begin();itr != phead->end(); itr++ ){
                string word = *itr;
                wordDict.erase(word);
                for(int i=0; i<(int)word.size();i++){
                    char letter = word[i];
                    for( int j=0; j<26 ; j++ ){
                        word[i] = 'a'+j;
                        if(ptail->find(word) != ptail->end())
                            return dist;
                        if(wordDict.find(word) != wordDict.end()){
                            temp.insert(word);
                            wordDict.erase(word);
                        }
                    }
                    word[i] = letter;
                }
            }
            dist++;
            swap(temp, *phead);
        }
        
        return 0;
    }
};