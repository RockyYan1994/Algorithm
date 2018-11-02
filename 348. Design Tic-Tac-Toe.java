/*

*/

//version 1(62 ms)
class TicTacToe {

    private int[] rows, cols;
    
    private boolean end;
    
    private int dia, antiDia;
    private int moves;
    private int n;
    
    /** Initialize your data structure here. */
    public TicTacToe(int n) {
        rows = new int[n];
        cols = new int[n];
        end = false;
        moves = 0;
        dia = 0;
        antiDia= 0;
        this.n = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    public int move(int row, int col, int player) {
        if (moves == n*n || end) {
            return 0;
        }
        int adder = player == 1 ? 1 : -1;
        if (row == col) {
            dia += adder;
        } 
        if (row == (n-col-1)) {
            antiDia += adder;
        }
        rows[row] += adder;
        cols[col] += adder;
        moves++;
        if (checkWin(row, col)) {
            end = true;
            return player;
        }
        
        return 0;
    }
    
    private boolean checkWin(int row, int col) {
        if (Math.abs(dia) == n || Math.abs(antiDia) == n || Math.abs(rows[row]) == n || Math.abs(cols[col]) == n) {
            return true;
        }        
        return false;
    }
}

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */