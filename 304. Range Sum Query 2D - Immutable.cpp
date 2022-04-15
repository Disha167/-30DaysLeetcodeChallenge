//🎯DAY 80 PROBLEM 1
/* Let us say: dp[row][col]-> represents sum of all nos in rectangle from 0,0 to row,col.
The approach is simple: To find the sum of all nos in rectangle from row1,col1 to row2,col2 , we find the dp[row2][col2] that means sum till row2,col2
and subtract dp[row2][col1-1] and dp[row1-1][col2] from them(to delete row1,col1 from row2,col2). And, since dp[row1-1][col1-1] is subtracted twice we
add them.

Now, to calculate dp[row][col], we add the dp[row-1][col] & dp[row][col-1] & current element i.e. matrix[row][col] but dp[row-1][col-1] is added twice so
we subtract them-> it is easy
*/
class NumMatrix {
public:
    vector<vector<int>> dp;
    NumMatrix(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++)
        {
            vector<int>row(matrix[0].size(),0);
            dp.push_back(row);
        }
        dp[0][0]=matrix[0][0];
        for(int i=1;i<matrix.size();i++)
        {
            dp[i][0]=dp[i-1][0]+matrix[i][0];
         
        }
        for(int j=1;j<matrix[0].size();j++)
        {
            dp[0][j]=dp[0][j-1]+matrix[0][j];
           
        }
        for(int i=1;i<matrix.size();i++)
        {
            for(int j=1;j<matrix[i].size();j++)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1]+matrix[i][j]-dp[i-1][j-1];
                
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
      /* just you have to consider the cases when the rectangle that you are subtracting or adding might give out of bound error*/
        int second=(row1>0)?dp[row1-1][col2]:0; 
        int third=(col1>0)?dp[row2][col1-1]:0;
        int fourth=(row1>0&&col1>0)?dp[row1-1][col1-1]:0;
        int ans= dp[row2][col2]-second-third+fourth;
        return ans;
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
