//🎯DAY 61 PROBLEM 1
//It is a topological sort problem. Things to be noted is that it is mentioned in the question that there may not be a valid order i.e. when there is a cycle, so we first 
//have to check that whether there is a cycle in the graph or not and if there will be a cycle, then maybe the indegree of any vertex is not 0 and finally it does
//not go inside the while loop so we check at end that whether ans.size()==numCourses because if ans has less members that is the while loop ended before only and there
//is a cycle, so it will return an empty vector.
//If there is no cycle, the logic behind the kahn's algorithm is to count all the indegree of every vertices and if indegree is 0 , then push them in the queue, now if
//we push a particular vertice into the ans vector, all the dependencies related to it are removed, and simultaneously if the indegree becomes 0 i.e. all the 
//prerequisities are already taken, then we push it into the answer.
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses+1);
        vector<int>ans;
        if(prerequisites.empty())
        {
            for(int i=0;i<numCourses;i++)
                ans.push_back(i);
            reverse(ans.begin(),ans.end());
            return ans;
        }
        vector<int>indegree(numCourses+1);
        for(int i=0;i<prerequisites.size();i++)
        {
            int x=prerequisites[i][0];
            int y=prerequisites[i][1];
            graph[y].push_back(x);
            indegree[x]++;
        }
        queue<int>q;
        vector<int>visited(numCourses+1);
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                visited[i]=1;
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int tp=q.front();
            q.pop();
            ans.push_back(tp);
            for(int x:graph[tp])
            {
                indegree[x]--;
                if(!visited[x]&&indegree[x]==0)
                {
                    visited[x]=1;
                    q.push(x);
                }
              
            }
        }
        //In dfs, we can check that whether a node is already visited or not but in bfs, this is a hack that we apply i.e. if we get a topological sort
        //it is linear and it will be equal to the total number of vertices, so we can check whether the no. of nodes present in topo sort is equal to
        //total no of courses.
        if(ans.size()==numCourses)//we check here for whether a cycle is there or not, if a cycle would be there then maybe the indegree of any vertice
          //will not be 0 or the while loop would end sooner so we go to the next else part and return an empty vector.
            return ans;
        else
            return {};
    }
};
