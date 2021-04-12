//🎯DAY 44 PROBLEM 1
//This is solved using the same concept as number of islands by dfs , we have converted each slash in a rectangle to form a grid of 3*3 squares as 2*2 dosen't work for some case.
//Then we will mark all the cells covering slash with 1. Like,if the input vector given is :
//' /'
//'/ '
//It can be converted as:
//000001
//000010
//000100
//001000
//010000
//100000
//It is now converted into number of islands, if we start from any element 0 in the grid, then we have to count how many element we can reach from this element(same as no. of 
//islands).Here, we can reach all the elements on the left hand side of the diagonal if we start from 0th index in 1 dfs traveral. As, we keep on reaching the elements,
//we keep on marking them visited. And, in another dfs traversal we can reach all the elements in the right hand side of the diagonal.So the answer will be 2 as we require
//2 traversals.
class Solution :
public:
    void dfs(int i,int j, vector<vector<int>>&g)
    {
       
        if(i <0||i>=g.size()||j<0||j>=g[0].size()||g[i][j]!=0)
        {
            return;
        }
        g[i][j]=1;
        dfs(i+1,j,g);
        dfs(i-1,j,g);
        dfs(i,j+1,g);
        dfs(i,j-1,g);
        
    }
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        vector<vector<int>>g(n*3,vector<int>(n*3,0));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='/')
                {
                    g[i*3][j*3+2]=1; //for making it visited
                    g[i*3+1][j*3+1]=1;
                    g[i*3+2][j*3]=1;
                }
                else if(grid[i][j]=='\\')
                {
                    g[i*3][j*3]=1;
                    g[i*3+1][j*3+1]=1;
                    g[i*3+2][j*3+2]=1;
                }      
            }
        }
                  int regions=0;
                for(int i=0;i<g.size();i++)
                {
                    for(int j=0;j<g[0].size();j++)
                    {
                        if(g[i][j]==0)
                        {
                            dfs(i,j,g);
                            regions++;
                        }
                    }
                }
         return regions;
        
    }
};
