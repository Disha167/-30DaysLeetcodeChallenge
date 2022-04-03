//🎯DAY 79 PROBLEM 1
/* Here, we have to find the edge that we can remove from the graph to make it uncycled from cycled, so first thing to notice is:
It can be any edge from cycle, if any edge from cycle is removed it becomes a non-cyclic graph.
But here, in this question we need to return the first occuring edge in edges vector from end so the approach here is to insert all the nodes in cycle in 
an unordered set and then traverse through the edges vector to find first such edge from end whose both nodes are in cycle set and that is our answer.

First, we create a graph(adjacency list) out of edges vector given, then we run dfs on 1 to get all edges in cycle. For that, once we first encounter an
already visited node ,we mark it as the start of the cycle and then returning back we push all the nodes untill we come across that start of cycle again,
that means our loop is completed we again mark it as -1 and do not push nodes further.

*/
class Solution {
public:
    void dfs_cycle(int source, vector<int> adj[], int parent, map<int,int>&visited, unordered_set<int>&edge_cycle,int &start_of_cycle)
    {
        
        visited[source]=1;
        for(int x:adj[source])
        {
            if(visited.find(x)==visited.end())
            {
                dfs_cycle(x,adj,source,visited,edge_cycle,start_of_cycle);/*it is used for making call to child nodes and on returning when we find a cycle,
                it comes here and then it checks the rest of the condition of inserting the nodes in set and if cycle has ended & so on.
                */
            }
            else if(x!=parent)/*if it is not visited, we have to also make sure that it is not parent so that it does not get stuck in infinite loop*/
            {
                start_of_cycle=x;/*as soon as we get the first visited node, we mark it as start of cycle and then keep on backtracking to the path which 
                got us here, and pushing all nodes that we encounter in the process to our set*/
                edge_cycle.insert(x);
                return; /*now, since we will reach the start_of_cycle, we keep on pushing edges to unordered_set*/
            }
            if(start_of_cycle==x)/*if we have reached the start of cycle again while returning that means our loop is complete and we turn start as -1
            as we dont need to insert in our set further*/
            {
                start_of_cycle=-1; return;
            }
            if(start_of_cycle!=-1)
            {
                edge_cycle.insert(x); 
                return;
            }
                
        }
     
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>adj[edges.size()+1];
        for(int i=0;i<edges.size();i++)
        {
           
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int parent=-1;
        map<int,int>visited;
        unordered_set<int>edge_cycle;
        int start_of_cycle=-1;
        dfs_cycle(1,adj,parent,visited,edge_cycle,start_of_cycle);
        vector<int>ans;
        for(int i=edges.size()-1;i>=0;i--)
        {
           if(edge_cycle.find(edges[i][0])!=edge_cycle.end()&& edge_cycle.find(edges[i][1])!=edge_cycle.end())
               return edges[i];
        }
                
        return ans;
            
    }
};
