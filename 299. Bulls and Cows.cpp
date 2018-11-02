/*
	方法一：终极复杂，
	方法二：一个循环统计每个数字的数量和bulls的数量，第二个循环计算cows的数量
*/

//version 1(16 ms)
class Solution {
public:
    string getHint(string secret, string guess) {
        if (secret.size() == 0) return "";
        int bulls = 0, cows = 0, n = secret.size();        
        unordered_map<char, unordered_set<int>> idx2pos;        
        for (int i=0; i<n; i++) {            
            idx2pos[secret[i]].insert(i);
        }
        unordered_map<char, int> idx2cnt;
        for (int i=0; i<n; i++) {
            char ch = guess[i];
            if (idx2pos.find(ch) != idx2pos.end() && idx2pos[ch].find(i) != idx2pos[ch].end()) {
                bulls++;                
            }
            idx2cnt[ch]++;
        }
        for (auto pair : idx2pos) {
            cows += min(idx2cnt[pair.first], (int)pair.second.size());
        }
        
        return to_string(bulls) + "A" + to_string(cows - bulls) + "B";
    }


//version 2(4 ms)
class Solution {
public:
    string getHint(string secret, string guess) {
        if (secret.size() == 0) return "";
        int bulls = 0, cows = 0, n = secret.size();
        vector<int> v1(10, 0), v2(10, 0);
        for (int i=0; i<n; i++) {            
            if (secret[i] == guess[i]) bulls++;
            v1[secret[i] - '0']++;
            v2[guess[i] - '0']++;
        }
        for (int i=0; i<10; i++) {
            cows += min(v1[i], v2[i]);
        }
        cows -= bulls;
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};