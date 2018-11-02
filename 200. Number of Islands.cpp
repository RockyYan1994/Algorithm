/*
	方法一、二思路相同：二比一稍微简化了一下。
	方法三：union-find
*/

//version 1(8 ms)
class Solution {
    int cnt;
    vector<pair<int, int>> dirs;
    void dfs(vector<vector<char>>& grid, pair<int, int> pos) {
        int x = pos.first, y = pos.second;
        if (grid[x][y] == '0' || grid[x][y] == '-') return;
        grid[x][y] = '-';
        for (int i=0; i<dirs.size(); i++) {
            int p = x+dirs[i].first, q = y+dirs[i].second;
            if (p>=0 && q>=0 && p<grid.size() && q<grid[0].size())
                dfs(grid, make_pair(p, q));                
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        cnt = 0;
        dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        if (grid.empty() || grid[0].empty()) return cnt;
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    cnt++;   
                    dfs(grid, make_pair(i, j));
                }                
            }
        }
        return cnt;
    }
};


//version 2(8 ms)
class Solution {    
    vector<pair<int, int>> dirs;
    void dfs(vector<vector<char>>& grid, pair<int, int> pos) {
        int x = pos.first, y = pos.second;
        if (grid[x][y] != '1') return;
        grid[x][y] = '0';
        for (int i=0; i<dirs.size(); i++) {
            int p = x+dirs[i].first, q = y+dirs[i].second;
            if (p>=0 && q>=0 && p<grid.size() && q<grid[0].size())
                dfs(grid, make_pair(p, q));                
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        if (grid.empty() || grid[0].empty()) return cnt;
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    cnt++;   
                    dfs(grid, make_pair(i, j));
                }                
            }
        }
        return cnt;
    }
};


//version 3()
class Solution {    
    int find(vector<int>& roots, int pos) {
    	while (pos != roots[pos]) {
    		roots[pos] = roots[roots[pos]];
    		pos = roots[pos];
    	}
    	return pos;
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
    	int cnt = 0;
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
        vector<int> roots(m*n, 0);
        for (int i=0; i<m; i++) {
        	for (int j=0; j<n; j++) {
        		if (grid[i][j] == '1') {
        			cnt++;
        			int pos = i*m + j;
        			roots[pos] = pos;
        		}
        	}
        }
        for (int i=0; i<m; i++) {
        	for (int j=0; j<n; j++) {
        		if (grid[i][j] == '1') {
        			int pos = i*m + j;
        			for (int k=0; k<dirs.size(); k++) {
        				int p = i+dirs[k].first, q = j+dirs[k].second;
        				if (p>=0 && q>=0 && p<m && q<n && grid[p][q] == '1') {
        					int r1 = find(roots, pos), r2 = find(roots, p*m + q);
        					if (r1 != r2) {
        						cnt--;
        						roots[r1] = r2;
        					}
        				}
        			}
        		}
        	}
        }
        return cnt;
    }
};