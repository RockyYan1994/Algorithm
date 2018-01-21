/*
    first
    首先想到使用map来作为每个数字对应的映射，但是参考discussion之后，发现可以直接采用vector<string>的方法来直接映射到0-9数字中，通过在查询的时候采用
    mapping[digits[i]-'0']，来进行查询字符串。本次算法采用外层遍历digits，每次遍历得到当前需要添加的str，然后通过内层两个循环（第一层为str，第二层为
    ret）来将str添加到ret的末尾。
    优化，在遇到0或者1的情况下，忽略掉该情况，if(str.empty()) continue;
*/
//version 1(5 ms)
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        vector<string> mapping = {"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        if(digits.size()==0) return ret;
        
        ret.push_back("");
        
        for(int i=0;i<digits.size();i++){
            vector<string> temp;
            string str = mapping[digits[i]-'0'];
            for(int k=0;k<str.size();k++){
                for(int j=0;j<ret.size();j++){
                    temp.push_back(ret[j]+str[k]);
                }
            }
            ret = temp;
        }
        return ret;
    }
};


//version 1(2 ms)
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        vector<string> mapping = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        if(digits.size()==0) return ret;
        
        ret.push_back("");
        
        for(int i=0;i<digits.size();i++){
            vector<string> temp;
            string str = mapping[digits[i]-'0'];
            if(str.empty()) continue;
            for(int k=0;k<str.size();k++){
                for(int j=0;j<ret.size();j++){
                    temp.push_back(ret[j]+str[k]);
                }
            }
            ret = temp;
        }
        return ret;
    }
};