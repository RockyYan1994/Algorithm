/*
    first
    首先想到使用最基本的分别遍历行，列，小矩阵的方法，看了discussion之后， 发现能够在一次遍历中实现。
    后来发现基本就是遍历，时间复杂度基本是O（n2）。
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        vector<vector<int> > row(n,vector<int>(n,0)),col(n,vector<int>(n,0));
        vector<vector<int> > sub_board(n,vector<int>(n,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]!='.'){
                    int num = board[i][j] - '0' -1;
                    int sub = i / 3 * 3 + j / 3;
                    if(row[i][num]||col[j][num]||sub_board[sub][num]) return false;
                    row[i][num]=1;
                    col[j][num]=1;
                    sub_board[sub][num]=1;
                }
                
            }
        }
        return true;
    }
};