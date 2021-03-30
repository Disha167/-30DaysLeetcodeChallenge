//🎯DAY 42 PROBLEM 1
//Using dfs and backtracking
//The idea is to make dfs calls for all the 4 neighbours and return true if any of the 4 calls return true that is why OR b/w them and if it returns false it keeps on checking
//other options.
class Solution {
public:

    bool dfs(int row,int col,  vector<vector<bool>> &visited,vector<vector<char>>&board,int index, string word)
    {
         if(index==word.length())
                    return true;
       //to check whether a partcular cell would be safe i.e. out of bound and whether is it visited previously or not and whether it is equal to the specific index
         if( (row < 0) || (row > board.size()-1) || (col < 0) ||(col > board[0].size()-1)||(visited[row][col])||(board[row][col]!=word[index]))
                return false;
        
           visited[row][col]=true;
 // We use all 4 function calls for exploring 4 directions top,bottom,left,right. If either of function calls will return true, then we return true to the parent function
 //that will further return true to its parent and then ultimately true will be returned by main function.
bool val= 
dfs(row-1,col,visited,board,index+1,word)||dfs(row,col-1,visited,board,index+1,word) ||dfs(row,col+1,visited,board,index+1,word)||dfs(row+1,col,visited,board,index+1,word);
            
        visited[row][col]=false;//once returning back to parent function, we make the current non-visited i.e. backtrack
        return val;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(7,vector<bool>(7,false));
        for(int row=0;row<board.size();row++)
        {
            for(int col=0;col<board[0].size();col++)
            {
                int index=0;
               if(board[row][col]==word[index]&&!visited[row][col])
                    if(dfs(row,col,visited,board,0,word))
                        return true;
                
            }
        }
        return false;
    }
};
