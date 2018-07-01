/*
	主要思路是对边界的每个点，判断是否为O，如果是则对这个点进行bfs，吧所有的O都改成1，然后通过遍历board，将剩余的O设成X，最后将1改为O。
*/

//version 1(22 ms)
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        int row = board.size();
        int col = board[0].size();
        for(int i=0;i<row;i++) {
            dfs(board, i, 0);
            if(col>1) dfs(board, i, col-1);
        }
        for(int i=1;i<col-1;i++) {
            dfs(board, 0, i);
            if(row>1) dfs(board, row-1, i);
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++)
                if(board[i][j] == 'O') board[i][j] = 'X';
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++)
                if(board[i][j] == '1') board[i][j] = 'O';
        }
        
    }
    void dfs(vector<vector<char>>& board, int i, int j){
        int row = board.size();
        int col = board[0].size();
        if(board[i][j] == 'O'){
            board[i][j] = '1';
            if(i>0) dfs(board, i-1, j);
            if(j>0) dfs(board, i, j-1);
            if(i<row-1) dfs(board, i+1, j);
            if(j<col-1) dfs(board, i, j+1);
        }
    }
};