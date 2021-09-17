//The approach is to fill the current slot and then go for next empty slot, if the next slot cant be filled given that the previous is already filled,
//we return false and then try another character in the previous slot. If the next slot can be filled given that the previous slot is filled, we move 
//on to further empty positions and as soon as we reach the last row, we keep on returning true backwards.
class Solution {
public:
    bool isvalid(int row, int col, char c,vector<vector<char>>&board )
    {
      //for checking validity, we check whether same number is their in same row, same col or same box
        for(int i=0;i<9;i++) 
        {
            if(board[row][i]==c)
                return false;
            if(board[i][col]==c)
                return false;
           
            if(board[3*(row/3)+ i/3][ 3*(col/3) + i%3]==c)
                return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>&board)
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='.')
                {
                    for(char c='1';c<='9';c++)
                    {
                        if(isvalid(i,j,c,board))
                        {
                            board[i][j]=c;
                            if(solve(board)==true)
                                return true;
                            else
                                board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;//when all the cells have been explored, we return true
        }
    void solveSudoku(vector<vector<char>>& board) {
        if(board.empty())
            return;
        solve(board);
    }
    

};
