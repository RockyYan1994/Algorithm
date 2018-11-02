/*
	方法一：查看discussion，通过getline实现。
	方法二：通过len+'@'实现
	
*/

//version 1(36 ms)
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = "";
        for (auto s : strs) res += s + '\0';
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        stringstream ss(s);
        vector<string> res;
        string line;
        while (getline(ss, line, '\0')) res.push_back(line);
        return res;
    }
};