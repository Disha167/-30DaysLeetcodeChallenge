//🎯DAY 58 PROBLEM 1
//Detection of cycle in a directed graph. If cycle is there,then the dependencies of courses can't be fulfilled.
class Solution {
public:
    bool dfs_iscycle(vector<int>adj[],vector<int>&visited,int source,vector<int>&recurse)
    {
        visited[source]=1;
        recurse[source]=1;
        for(auto x:adj[source])
        {
            if(recurse[x]==1)
                return true;
            
            if(!visited[x])
            {
                if(dfs_iscycle(adj,visited,x,recurse)==true)
                {
                    cout<<"true 2 "<<x<<endl;
                    return true;
                }
            }
          
            
        }
        recurse[source]=0;
        return false;
        
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses+1];
        for(int i=0;i<prerequisites.size();i++)
        {
            
                int u=prerequisites[i][0];
                int v=prerequisites[i][1];
                adj[v].push_back(u);
            
        }
       vector<int>visited(numCourses+1,0);
        vector<int>recurse(numCourses+1,0);
        for(int i=0;i<numCourses;i++)
        {
            
            if(!visited[i])
            {
                
                if(dfs_iscycle(adj,visited,i,recurse)==true)
                    return false;
            }
        }
        return true;
    }
};
