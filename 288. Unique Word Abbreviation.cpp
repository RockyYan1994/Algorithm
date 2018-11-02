/*

*/

//version 1()
class ValidWordAbbr {
    unordered_map<string, string> words;
    
    string abbreviation(string full) {
        if (full.size() <=2) return full;
        string res;
        int n = full.size();
        res = full[0] + to_string(n-2) + full[n-1];
        return res;
    }
public:
    ValidWordAbbr(vector<string> dictionary) {
        for (auto word : dictionary) {
            string abr = abbreviation(word);
            if (words.find(abr) != words.end() && words[abr] != word) words[abr] = "-1";
            else words[abr] = word;
        }
    }
    
    bool isUnique(string word) {
        string abr = abbreviation(word);
        return words.find(abr) == words.end() || words[abr] == word;
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */