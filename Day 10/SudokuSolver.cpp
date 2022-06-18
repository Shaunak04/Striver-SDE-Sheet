class Solution 
{
public:
    
    bool check(vector<vector<char>>& board, int row, int col, char& num)
    {
        int curr_row = row - row%3, curr_col = col-col%3;
        for(int x=0; x<9; x++) if(board[x][col]==num) return false;
        for(int y=0; y<9; y++) if(board[row][y]==num) return false;

        for(int i = 0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(board[curr_row+i][curr_col+j]==num) return false;
            }
        }
        return true;
    }
    
    bool fillSudoku(vector<vector<char>>& board, int row, int col)
    {
        if(row==9) return true; // sudoku complete
        if(col==9) return fillSudoku(board, row+1, 0); // this row is complete, move to next row
        if(board[row][col]!='.')
        {
            return fillSudoku(board, row, col+1);
        }
        for(char i='1'; i<='9'; i++)
        {
            if(check(board, row, col, i))
            {
                board[row][col] = i; // give
                if(fillSudoku(board, row, col+1)) return true;
                board[row][col] = '.'; // take
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) 
    {
        fillSudoku(board, 0, 0);   
    }
};