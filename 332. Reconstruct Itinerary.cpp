//🎯DAY 38 PROBLEM 1
//Also called finding euler path, the game that you must have played in your childhood to connect all the dots of a hut without repeating a line and without stopping the pencil 😅
//Learnt how to create a graph using unordered_map of string and multiset
//Multiset is used to lexicographically sort all the neighbours of a given vertex automatically
//Then we can just use any bfs or dfs traversal to visit the first neighbour of every vertex, then delete that edge, and further visit the adjacency list of the first neighbour
//and continue the process but this simple solution fails in some edge test cases . Eg:
//          J*
//        /  \\
//       K*   N*
//* means that edge is directed form J to K, in above graph there is anedge from J to K, from J to N , from N to J.
//Using, our simple solution we go to lexicographically smallest neighbour of J i.e. K and then look for neighbours of K so that will be a dead end.
//So, we have to give more priority to traversing all edges once then finding lexographically shortest, here stack comes to rescue.
//For above example, we push J into stack, visit neighbours of J i.e. K (first lexicographically), push it into stack. When we see that it's adjacent list size is 0, so we pop
//it(BACKTRACKING) from stack and push it in answer vector , then see top of stack  J , check it's first neighbour i.e. N now as K is removed(processed),push N in stack, check
//adj list of N, push J in stack. Now J's adj list is empty so we pop J and push it in answer vector then pop the elements N,J one by one and push it in ans and finally reverse
//the ans vector. 
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>>adj;
        for( int i=0;i<tickets.size();i++)
        {
            adj[tickets[i][0]].insert(tickets[i][1]);
        }
        stack<string>st;
        vector<string>ans;
        st.push("JFK");
        while(!st.empty())
        {
            string tp=st.top();
            if(adj[tp].size()==0)
            {
                st.pop();
                ans.push_back(tp);
            }
            else
            {
               st.push(*(adj[tp].begin()));
                adj[tp].erase(adj[tp].begin());//to make sure that we use one edge only once
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
        
    }
};
//Same thing can be done using dfs
class Solution {
    void dfs(unordered_map<string, multiset<string>>& adj, vector<string>& result, string s){
        while(adj[s].size()){
            string v = *(adj[s].begin());
            adj[s].erase(adj[s].begin());//making sure that we use one edge only once.
            dfs(adj, result, v);
        }
        //WHEN adj list size becomes zero then we push it in result
        result.push_back(s);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> adj;
        for(vector<string>& t: tickets)
            adj[t[0]].insert(t[1]);
        
        vector<string> result;
        dfs(adj, result, "JFK");
        reverse(result.begin(), result.end());
        return result;
    }
};
