//🎯DAY 47 PROBLEM 1
//Here we have to find all the paths from 0 cell to 2 cell given the condition that you cannot cross obstacles i.e. cell containing -1 and you have to pass through each non
//obstacle cell exactly once.  Similar to the no. of islands, we iterate through every row and col co-ordinates, and do dfs if we pass through the starting cell i.e. 1
//In dfs, to make sure we do not visit any non-obstacle cell more than once, we use visited array and to keep a track that whether we are visiting each cell once or not, we
//count the total number of non-obstacle cells before making a dfs call and check whether the count of cells visited in dfs calls is equal to no of non-obstacle cells or not.
class Solution {
public:
void dfs(int total_no_of_non_obstacle_cell,int no_of_non_obstacle_cell, vector<vector<int>>&grid,vector<vector<int>>&visited,int &paths,int i,int j)
{
    
    if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||visited[i][j]==1||grid[i][j]==-1)//if the cell is invalid, we return.
        return;
    if(i>=0&&i<grid.size()&&j>=0&&j<grid[0].size()&&grid[i][j]==2)
    {
        
        if(no_of_non_obstacle_cell==total_no_of_non_obstacle_cell+1)//check if total_no_of_non-obstacle-cells is equal to non_obstacle cells visited in the path.We add 1
          //as one extra ending cell is also counted in the last call
        {
            //cout<<no_of_non_obstacle_cell<<endl;
            paths=paths+1;
        }
        return;
    }
   // cout<<i<<" "<<j<<" "<<no_of_non_obstacle_cell<<endl;
    visited[i][j]=1;
 
    dfs(total_no_of_non_obstacle_cell,no_of_non_obstacle_cell+1,grid,visited,paths,i+1,j);
    dfs(total_no_of_non_obstacle_cell,no_of_non_obstacle_cell+1,grid,visited,paths,i-1,j);
    dfs(total_no_of_non_obstacle_cell,no_of_non_obstacle_cell+1,grid,visited,paths,i,j+1);
    dfs(total_no_of_non_obstacle_cell,no_of_non_obstacle_cell+1,grid,visited,paths,i,j-1);
    visited[i][j]=0;//BACKTRACK:if none of the paths are valid then we make the current cell unvisited and return to the parent function to explore other options.
    
}
    int uniquePathsIII(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int total_no_of_non_obstacle_cell=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
                if(grid[i][j]==0)
                    total_no_of_non_obstacle_cell++;
        }
        int paths=0;
       for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                vector<vector<int>>visited(row+1,vector<int>(col+1,0));
             
                if(grid[i][j]==1)
                {
                    
                    dfs(total_no_of_non_obstacle_cell,0,grid,visited,paths,i,j);
                }
            }
        }
        return paths;
    }
};
