class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        vector<int>ans;
        //for(int i=0;i<nums.size();i++)
            
        for(int i=0;i<nums.size();i++)
        {
            //🔑🔑Here the array element serve as keys and indexes as value. So, below in find function, the array element is searched for as a key⭐️⭐️
            if(mp.find(target-nums[i])!=mp.end())
            {
                ans.push_back(i);
                auto it=mp.find(target-nums[i]);
                ans.push_back(it->second);   
                break;
            }
            //🧐🧐To avoid counting one element twice, like if array is 3, 2, 4 and we have to count for target 6 then adding 3 in the map before checking find condition
            //will give 0,0 i.e the wrong answer.So, we just check for the elements added befpre the specific element for pairs
     
            mp[nums[i]]=i;
            //📌📌mp[nums[i]]=i is equivalent to mp.insert{nums[i],i};
            //Here, key is nums i which is used for search for the pair using find function above
        }
        return ans;
    }
};
