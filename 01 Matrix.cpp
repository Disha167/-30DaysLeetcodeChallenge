//🎯DAY 84 PROBLEM 1
/*This is a problem of Multi-source BFS. The only difference between Single-source & Multi-source BFS is that here we push all the sources initially into 
the queue instead of only one source. So, here we have to find the nearest 0 from each cell, so the optimised approach is to call bfs from every zero
& maintain the matrix for updating the distance of all cells. THE THING TO KEEP IN MIND IS FIRST 1ST LEVEL OF ALL SOURCES ARE VISITED THEN 2ND LEVEL OF
ALL SOURCES & SO ON, so if a cell is reached from 2 zeros, then we are bound to reach by the nearest distance as smallest level is traversed first. So, we
need to visit every cell only once & can maintain a visited array. So, time complexity of Multi-source bfs is O(N*N), where N is no fo rows & coloums in
matrix as every cell is visited once only.

*/
class Solution {
public:
    /*isme sb 0 se har cell visit krne ki zaroorat ni hai, ekbaar 1 cell visit hogyi toh uske baad us se shortest distance ni mil skta... kyunki har 0
    ka pehle 1st level visit hoga fr har zero ka 2nd level toh agar maanlo 1 cell me 1st level se bhi reach ho rha, 2nd level se bhi toh 1st level humesha
    pehle visit ho jaega 2nd level se*/
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>>q;
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>ans(m,vector<int>(n,0));
        vector<vector<int>>visited(m,vector<int>(n,-1));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                    visited[i][j]=1;
                }
            }
        }
        vector<vector<int>>dir{{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty())
        {
            pair<int,int> tp=q.front();
            q.pop();
            for( auto directions: dir)
            {
                int new_row=directions[0] + tp.first;
                int new_col=directions[1] + tp.second;
                if(new_row>=0&&new_row<m&&new_col>=0&&new_col<n&&visited[new_row][new_col]==-1) /*if the cell is not visited and is valid, then push it
                into queue & mark it visited*/
                {
                    ans[new_row][new_col]=ans[tp.first][tp.second]+1;
                    q.push({new_row,new_col});
                    visited[new_row][new_col]=1;
                }
            }
            
        }
        return ans;
        
    }
};
