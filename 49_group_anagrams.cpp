/*
	first
	首先想到使用unordered map和sort字符串来实现，但是对二维的vector处理不熟悉，在查看discussion之后才完成。
*/

version 1(X)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res;
        unordered_map<string,int > um; 
        int count=0;
        for(int i=0;i<strs.size();i++){
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            unordered_map<string,int>::iterator it = um.find(temp);
            if(it == um.end()){
                um.insert({temp,count++});
                res[count].push_back(strs[i]);
            }
            else{
                res[it->second].push_back(strs[i]);
            }
            
        }
        return res;
    }
};

//version 2(32 ms)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res;
        unordered_map<string,vector<string> > um; 
        for(int i=0;i<strs.size();i++){
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            um[temp].push_back(strs[i]);
        }
        for(auto m:um){
            vector<string> temp(m.second.begin(),m.second.end());
            res.push_back(temp);
        }
        return res;
    }
};