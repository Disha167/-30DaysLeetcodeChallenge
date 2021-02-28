 //🎯DAY 36 PROBLEM 1
//This is a djikstra based problem just the additional constraint is of within k stops
//We make a adjacency matrix of vector of pair to push distance along with the source and then we use min heap that at every step is used to extract the minimum distance untill
//k becomes 0, as we are allowed to have maximum k stops only(i.e. why we make a heap of vectors to update the distance, source and no. of stops everytime). It works for every 
//test case as it follows the greedy approach of taking the least priced path everytime, hence overall giving the least price
class Solution {
public:

   
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K)
    {
        
        vector <pair<int, int> > adj[n+1];
        for(int i=0;i<flights.size();i++)
        {
                int src=flights[i][0];
                int dst=flights[i][1];
                int price=flights[i][2];
            adj[src].push_back(make_pair(dst, price)); 
        }
       priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,src,K+1});//as for k stops, we can have k+1 edges
        while(!pq.empty())
        {
            vector<int>tp=pq.top();
            int curr_price=tp[0];
            int curr_source=tp[1];
            int edges=tp[2];
            pq.pop();
            if(curr_source==dst)//if a vertex has been popped from the queue i.e it has been finalised so when destination is popped that means we have got our answer i.e. the 
              //path with minimum price
                return curr_price;
            if(edges>0)
            {
                for(auto &x:adj[curr_source])
                {
                    pq.push({curr_price+x.second,x.first,edges-1});//we update the value of edge at every level
                }
            }
        }
        return -1;
    }
};
