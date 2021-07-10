//🎯DAY 55 PROBLEM 1
//The approach is to use bfs and keep on coloring one level at a time, and then coloring the adjacent of that level with a different color if it is not colored but
//if it is already colored then check whether it is different from the color of the node.
//For coloring, we create a vector and make it's value 0 or 1 as it is bipartite graph so two colors are used.

class Solution {
public:
    bool bfsBipartite(int source, vector<int>&color,vector<vector<int>>&graph,int n)
    {
        queue<int>q;
        q.push(source);
        color[source]=0;
        while(!q.empty())
        {
            int tp=q.front();
            q.pop();
            for(auto x:graph[tp])
            {
                if(color[x]==-1)
                {
                    q.push(x);
                    color[x]=(color[tp]==1)?0:1;//if it is not colored, color it with opposite color
                }
                else 
                {
                    if(color[x]==color[tp])//if it is colored, check whether it is of opposite color than adjacent node
                        return false;
                }
            }
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
                if(!bfsBipartite(i,color,graph,n))
                    return false;
            }
        }
        return true;
        
    }
};
