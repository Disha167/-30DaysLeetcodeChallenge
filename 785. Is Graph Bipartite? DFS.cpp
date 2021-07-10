//🎯DAY 55 PROBLEM 2
//The approach is to perform a dfs and keep on coloring the adjacent opposite to your current node, if you find any of the adjacent of any node colored same, then 
//you return false because we are coloring the nodes in an optimal way such that avoiding the 2 adjacent nodes 2 be colored same on every step.
class Solution {
public:
    bool dfsBipartite(vector<int>&color,vector<vector<int>>&graph,int parent)
    {
        
       
        for(auto x:graph[parent])
        {
            if(color[x]==-1)
            {
                color[x]=1-color[parent];
                if(!dfsBipartite(color,graph,x))//**IMP** if any one of the dfsBipartite calls return false, then the whole dfs returns false.
                
                    return false;
            }
            else if(color[x]==color[parent])
                return false; //even when one of them returns a false, you return false to the parent.
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n+1,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                color[i]=0;
                if(!dfsBipartite(color,graph,i))
                    return false;
            }
        }
        return true;
        
    }
};
