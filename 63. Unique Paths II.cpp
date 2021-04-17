//🎯DAY 46 PROBLEM 1
//The dp equation i.e. the logic is same as unique paths  problem dp[i][j]=dp[i-1][j] i.e the number of ways to reach a particular grid is sum of no. of ways to reach 2 
//cells, one of previous row & one of previous coloumn. Only, the difference here is in define dp state of 0th row and 0th coloumn, normally we used to put 1 in both 0th row
//and 0th coloumn(as only downward movement is allowed for coloumn and righ movement for row so there is only 1 way to reach all cells of 0th row and 0th coloumn)
//but when an obstacle is there on dp[i][0], then we can't reach any of dp[i+1][0],dp[i+2][0],....,dp[i+n][0] so all of the cells of 0th coloumn after the obstacle will be 0.
//Rest of the code will be same.
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1)
            return 0;
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(m==1)
        {
            for(int i=0;i<n;i++)
                if(obstacleGrid[m-1][i]==1)
                    return 0;
            return 1;
        }
        if(n==1)
        {
            for(int i=0;i<m;i++)
                if(obstacleGrid[i][n-1]==1)
                    return 0;
            return 1;
        }
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        int flag=0;
        int i=0;
        for(int j=0;j<n;j++)
        {
            if(obstacleGrid[i][j]==1)
                flag=1;
            if(flag==1)
                dp[i][j]=0;
            else
                dp[i][j]=1;
       }
       int j=0;
        flag=0;
          for(int i=0;i<m;i++)
        {
            if(obstacleGrid[i][j]==1)
                flag=1;
            if(flag==1)
                dp[i][j]=0;
            else
                dp[i][j]=1;
       }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
             
                 if(obstacleGrid[i][j]==0) 
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                    
            }
        }
      
        return dp[m-1][n-1];
    }
};
