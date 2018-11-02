/*
	方法一：根据规则，通过新开一个数组实现，
	方法二：通过两个bit来实现状态。
*/

//version 1()
class Solution {
    const vector<pair<int, int>> neighbors {make_pair(0,1), make_pair(1,1),make_pair(1,0),make_pair(1,-1),make_pair(0,-1),make_pair(-1,-1),make_pair(- 1,0),make_pair(-1,1)};
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty() || board[0].empty()) return;
        vector<vector<int>> res(board.size(), vector<int>(board[0].size(), 0));
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                res[i][j] = helper(board, i, j);
            }
        }
        board = res;
    }
    
    int helper(vector<vector<int>>& board, int x, int y) {
        int m = board.size(), n = board[0].size();
        int cnt = 0;
        for (int i=0; i<neighbors.size(); i++) {
            int p = x+neighbors[i].first, q = y+neighbors[i].second;            
            if (p>=0 && q>=0 && p<m && q<n) {
                cnt += board[p][q] ? 1 : 0;
            }
        }
        
        if (cnt == 3) {
            return 1;
        } else if (cnt == 2) {
            return board[x][y];
        } else {
            return 0;
        }
    }  
};

//version 2(0 ms)
class Solution {
    const vector<pair<int, int>> neighbors {make_pair(0,1), make_pair(1,1),make_pair(1,0),make_pair(1,-1),make_pair(0,-1),make_pair(-1,-1),make_pair(- 1,0),make_pair(-1,1)};
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty() || board[0].empty()) return;
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                helper(board, i, j);
            }
        }
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                board[i][j] >>= 1;
            }
        }        
    }
    
    void helper(vector<vector<int>>& board, int x, int y) {
        int m = board.size(), n = board[0].size();
        int cnt = 0;
        for (int i=0; i<neighbors.size(); i++) {
            int p = x+neighbors[i].first, q = y+neighbors[i].second;            
            if (p>=0 && q>=0 && p<m && q<n) {
                cnt += board[p][q] & 1;
            }
        }
        
        if (cnt == 3) {
            board[x][y] |= 2;
        } else if (cnt == 2) {
            board[x][y] |= board[x][y] << 1;
        }
    }  
};