//🎯DAY 83 PROBLEM 1
/*
Here, we have to schedule tasks in minimum cpu time . The only twist is we do cannot run the same process before n cooldown time. For this min cpu time,
we need to greedily process all the tasks first that is most frequent, then between them try to accomodate all the 2nd most frequent tasks then 3rd most
frequent & so on untill space is there..
KIND OF GREEDY APPROACH BUT IMPLEMENTATION & APPROACH IS TOUGH
Here, we have to schedule the tasks such that between the most frequent tasks, you schedule the second most frequent tasks & other tasks during cooldown.
So , we run through all the tasks again & again and maintain the tasks according to their frequency in the maximum heap. Everytime while going through all
the elements to execute we use the min heap, so everytime most frequent element is executed.
If there is no same process , so n+1 cooldown will not occur, then the cooldown will be there for no of tasks left otherwise we have to wait n+1 for 
next process to occur.
*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0) return tasks.size();
        priority_queue<pair<int,char>>max_heap;
        unordered_map<char,int>mp;
        for(int i=0;i<tasks.size();i++)
        {
            mp[tasks[i]]++;
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            max_heap.push({it->second,it->first});
            // cout<<it->second<<" "<<it->first<<endl;
        }
        int ans=0;
        // while(!max_heap.empty()){
        //     cout<<max_heap.top().first<<" "<<max_heap.top().second<<endl;
        //     max_heap.pop();
        // }
        while(!max_heap.empty())
        {
            vector<pair<int,char>>curr_tasks;
            for(int i=0;i<n+1;i++)
            {
                if(!max_heap.empty())
                {
                    curr_tasks.push_back(max_heap.top());
                    max_heap.pop();
                }
            }
            for(int i=0;i<curr_tasks.size();i++)
            {
                // cout<<curr_tasks[i].first<<" "<<curr_tasks[i].second<<endl;
                if(--curr_tasks[i].first>0)
                {
                    max_heap.push({curr_tasks[i].first,curr_tasks[i].second});
                    // cout<<max_heap.top().first<<" "<<max_heap.top().second<<endl;
                }
            }
            ans+=max_heap.empty()?curr_tasks.size():n+1;
            
        }
        return ans;
        
    }
};
