class Solution {
public:
    bool canCross(vector<int>& stones) {
        queue<pair<int,int>>q;
        q.push({0,0});
        /*{0,0} is pushed first , as the first jump needs to be of size 1, so the possible positons could be 1,-1 and 0 . For not pushing 0 again, we use visited,
        for not pushing -1, we have seen , we can only jump on stones, not water.*/
        set<pair<int,int>>visited;
        visited.insert({0,0});
        int n=stones[stones.size()-1];
        unordered_set<int>seen;
        for(int i=0;i<stones.size();i++)
        {
            seen.insert(stones[i]); /*we can only jump on stones*/
        }
        /*We keep track of all the possible positions in queue, and we avoid tle by keeping track in visited and storing only those that are stones in seen*/
        while(!q.empty())
        {
            pair<int,int>tp=q.front();
            int curr_pos=tp.first;
            int curr_size=tp.second;
            if(curr_pos==n) /*if we have reached the last stone, then we return true*/
                return true;
            q.pop();
            if(curr_pos+curr_size!=curr_pos&&(seen.find(curr_pos+curr_size)!=seen.end())&&(visited.find({curr_pos+curr_size,curr_size})==visited.end()))
            {
                q.push({curr_pos+curr_size,curr_size});
                visited.insert({curr_pos+curr_size,curr_size});
            }
            if(curr_pos+curr_size+1!=curr_pos&&(seen.find(curr_pos+curr_size+1)!=seen.end())&&(visited.find({curr_pos+curr_size+1,curr_size+1})==visited.end()))
            {
                q.push({curr_pos+curr_size+1,curr_size+1});
                visited.insert({{curr_pos+curr_size+1,curr_size+1}});
                
            }
            if(curr_pos+curr_size-1!=curr_pos&&(seen.find(curr_pos+curr_size-1)!=seen.end())&&(visited.find({curr_pos+curr_size-1,curr_size-1})==visited.end()))
            {
                q.push({curr_pos+curr_size-1,curr_size-1});
                visited.insert({{curr_pos+curr_size-1,curr_size-1}});
            }
        }
        return false;
    }
};
