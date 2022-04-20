//🎯DAY 82 PROBLEM 1
/*We have to find the maximum time after which all the nodes should have got light from k, i.e. maximum shortest distance from the source to all the nodes
. So, we apply djikstra here to find the shortest path length from source to all the nodes & then find maximum among them. 
*/
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<times.size();i++)
        {
            int src=times[i][0];
            int des=times[i][1];
            int weight=times[i][2];
            adj[src].push_back({des,weight});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>min_heap;
        vector<int>dis(n+1,INT_MAX);
        int ans=-1;
        dis[k]=0;/*distance from source to source is 0, so we need to set it 0 before going through all the other nodes.e*/
        min_heap.push({0,k});
        while(!min_heap.empty())
        {
            auto tp=min_heap.top();
            int prev_node=tp.second;
            min_heap.pop();
            for(auto it:adj[prev_node])
            {
                int next_node=it.first;
                int wt=it.second;
                if(dis[prev_node]+wt<dis[next_node])
                {
                    dis[next_node]=dis[prev_node]+wt;
                    min_heap.push({dis[next_node],next_node});
                    
                }
            }
            
        }
        ans= *max_element(dis.begin()+1,dis.end());
        return ans==INT_MAX?-1:ans; /*if the answer is INT_MAX , that means it is not possible to reach all nodes from k so we return -1*/
    }
};
