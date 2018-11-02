/*
	方法一：注意这个问题有一个没描述清楚的点， 就是只能从“++” 到 “--”。
*/

//version 1()
class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        if (s.size() < 2) return res;
        for (int i=0; i<s.size()-1; i++) {
            string temp = s;
            if (temp.substr(i, 2) == "++") {
                temp[i] = '-';
                temp[i+1] = '-';
                res.push_back(temp);
            }
        }
        return res;
    }
};