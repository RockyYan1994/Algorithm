/*
    first 
    第一个方法采用遍历每一个元素，对每一个元素进行判断，递归查看其所有可能满足条件的子序列。优化主要可以考虑整合代码，解决重复代码，同时可以调整顺序，
    减少代码的执行次数。
*/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size()==0) return true;
        if(board.size()==0 || board[0].size()==0) return false;
        int x,y;
        x = board.size()-1;
        y = board[0].size()-1;
        for(int i=0;i<=x;i++){
            for(int j=0;j<=y;j++){
                if(board[i][j] == word[0]) {     
                    if(word.size()==1) return true;
                    bool res = false;
                    char temp = board[i][j];
                    string new_word(word,1,word.size()-1);
                    board[i][j] = ' ';
                    res = exists(board,new_word,i,j);
                    if(res) return true;
                    else board[i][j] = temp;
                }
            }
        }
        return false;
    }
    bool exists(vector<vector<char>> board,string word,int x,int y){
        bool res = false;
        // vector<vector<int>> arr;
        // if(x+1<board.size() && board[x+1][y]==word[0]) arr.push_back({x+1,y});
        // if(y+1<board.size() && board[x][y+1]==word[0]) arr.push_back({x+1,y});
        // if(x+1<board.size() && board[x+1][y]==word[0]) arr.push_back({x+1,y});
        // if(x+1<board.size() && board[x+1][y]==word[0]) arr.push_back({x+1,y});
        if(x+1<board.size() && board[x+1][y]==word[0]){
            if(word.size()==1) return true;
            char temp = board[x+1][y];
            board[x+1][y] = ' ';            
            string new_word(word,1,word.size()-1);
            res = exists(board,new_word,x+1,y);
            if(res) return true;
            else board[x+1][y] = temp;
        }
        if(y+1<board[0].size() && board[x][y+1]==word[0]){
            if(word.size()==1) return true;
            char temp = board[x][y+1];
            board[x][y+1] = ' ';
            string new_word(word,1,word.size()-1);
            res = exists(board,new_word,x,y+1);
            if(res) return true;
            else board[x][y+1] = temp;
        }
        if(x-1>=0 && board[x-1][y]==word[0]){
            if(word.size()==1) return true;
            char temp = board[x-1][y];
            board[x-1][y] = ' ';
            string new_word(word,1,word.size()-1);
            res = exists(board,new_word,x-1,y);
            if(res) return true;
            else board[x-1][y] = temp;
        }
        if(y-1>=0 && board[x][y-1]==word[0]){
            if(word.size()==1) return true;
            char temp = board[x][y-1];
            board[x][y-1] = ' ';
            string new_word(word,1,word.size()-1);
            res = exists(board,new_word,x,y-1);
            if(res) return true;
            else board[x][y-1] = temp;
        }
        return false;
    }
};