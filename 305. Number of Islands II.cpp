/*
	方法一：对每一组island采用标记，每次进入的时候进行一次判断。
		如果是孤岛，分配新的island number， cnt++， 
		如果是周围一个岛，分配相同的number，返回cnt
		如果是多个岛，更新所有岛屿的number成一个，然后cnt - (周围island 数量 - 1)； 由于更新的时候是O(n^2)，所以很慢。
	方法二：采用UNION-FIND，用一个vector<int>(m*n, -1)来初始化。
*/

//version 1(696 ms)
class Solution {
    int cnt = 0;
    int number = 0;
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> res;
        if (m==0 || n==0) return res; 
        vector<vector<int>> land(m, vector<int>(n, 0));
        for (auto pos : positions) {
            res.push_back(addLand(land, pos));
        }
        return res;
    }
    
    int addLand(vector<vector<int>>& land, pair<int, int> pos) {
        int x = pos.first, y = pos.second;
        set<int> islands = countIsland(land, pos);
        if (islands.empty()) {
            land[x][y] = ++number;
            cnt++;
        } else if (islands.size() == 1) {
            land[x][y] = *(islands.begin());
        } else {
            int new_number = *(islands.begin());
            refreshIslandNumber(land, islands, new_number);
            land[x][y] = new_number;
            cnt -= islands.size() - 1;
        }
        return cnt;
    }
    
    set<int> countIsland(vector<vector<int>>& land, pair<int, int> pos) {
        const vector<vector<int>> dirs{{0,1}, {1,0}, {0,-1}, {-1,0}};
        set<int> islands;
        int x = pos.first, y = pos.second;
        for (int i=0; i<dirs.size(); i++) {
            int p = x + dirs[i][0], q = y + dirs[i][1];
            if (p>=0 && q>=0 && p<land.size() && q<land[0].size() && land[p][q] != 0) {
                islands.insert(land[p][q]);
            }
        }
        return islands;
    }
    
    void refreshIslandNumber(vector<vector<int>>& land, set<int>& islands, int new_number) {
        for (int i=0; i<land.size(); i++) {
            for (int j=0; j<land[0].size(); j++) {
                if (islands.find(land[i][j]) != islands.end()) land[i][j] = new_number;
            }
        }
    }
};

//version 2(64 ms)
class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        int cnt = 0;
        vector<int> res;
        if (m == 0 || n == 0) return res;
        vector<int> roots(m*n, -1);
        const vector<pair<int, int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        for (auto pos : positions) {
            int x = pos.first, y = pos.second;
            int xy = x*n + y;                
            roots[xy] = xy;
            int root = xy;
            cnt++;            
            for (auto dir : dirs) {
                int p = x + dir.first, q = y + dir.second;
                int pq = p*n + q;                
                if (p>=0 && q>=0 && p<m && q<n && roots[pq] != -1) {
                    int rootPQ = findIsland(roots, pq);
                    if (rootPQ != root) {                        
                        roots[root] = rootPQ;
                        root = rootPQ;
                        cnt--;
                    }
                }
            }
            res.push_back(cnt);
        }
        return res;
    }
    
    int findIsland(vector<int>& roots, int pos) {
        while (pos != roots[pos]) {
            pos = roots[pos]; 
        }
        return pos;
    }
};