/*
	方法一：采用bfs实现。
	方法二：进行多个优化。
*/

//version 1(72 ms)
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty() ||rooms[0].empty()) return;
        for (int i=0; i<rooms.size(); i++) {
            for (int j=0; j<rooms[0].size(); j++) {
                if (rooms[i][j] == 0) bfs(rooms, i, j);
            }
        }
    }
    
    void bfs(vector<vector<int>>& rooms, int x, int y) {
        const int ptr[] = {0, 1, 0, -1, 0};
        queue<pair<int, int>> q;
        q.push(make_pair(x, y));
        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            int i = cur.first, j = cur.second;
            for (int k=0; k<4; k++) {
                int m = i+ptr[k], n = j+ptr[k+1];
                if (m>=0 && n>=0 && m<rooms.size() && n<rooms[0].size() && rooms[m][n] > rooms[i][j]) {
                    rooms[m][n] = rooms[i][j] + 1;
                    q.push(make_pair(m, n));
                }
            }
        }
    }
};

//version 2(68 ms)
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty() ||rooms[0].empty()) return;
        const int ptr[] = {0, 1, 0, -1, 0};
        queue<pair<int, int>> q;     
        for (int i=0; i<rooms.size(); i++) {
            for (int j=0; j<rooms[0].size(); j++) {
                if (rooms[i][j] == 0) q.push(make_pair(i, j));
            }
        }
        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            int i = cur.first, j = cur.second;
            for (int k=0; k<4; k++) {
                int m = i+ptr[k], n = j+ptr[k+1];
                if (m>=0 && n>=0 && m<rooms.size() && n<rooms[0].size() && rooms[m][n] > rooms[i][j]) {
                    rooms[m][n] = rooms[i][j] + 1;
                    q.push(make_pair(m, n));
                }
            }
        }
    }
};