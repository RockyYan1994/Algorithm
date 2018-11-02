/*

*/

//version 1(4 ms)
class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> pre, suc;
        string last;
        set<char> all;
        string res;
        for (auto cur : words) {
            all.insert(cur.begin(), cur.end());
            for (int i=0; i<min(last.size(), cur.size()); i++) {
                if (last[i] != cur[i]) {
                    pre[cur[i]].insert(last[i]);
                    suc[last[i]].insert(cur[i]);
                    break;
                }
            }
            last = cur;
        }
        int n = all.size();
        for (auto pair : pre) all.erase(pair.first);
        set<char> free(all);
        while(!free.empty()) {
            char ch = *(free.begin());
            res += ch;
            free.erase(ch);
            for (auto suc_ch : suc[ch]) {
                pre[suc_ch].erase(ch);
                if (pre[suc_ch].empty()) free.insert(suc_ch);
            }             
        }
        cout << "n:" <<n <<", res.size(): " << res.size() << endl;
        return res.size() == n ? res : "";
    }
};