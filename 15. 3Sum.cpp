//DAY 11 PROBLEM 1
//WITHOUT USING SET
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //rest implementation is easy, just the point to keep in mind is that 
        //here dublicate triplets ids prohibited so we will check whether the number 
        //from where we begin is repeated or not .
        //Because, if we start from a number, we cover all the triplets that will
        //contain this number
        //BUT, WE HAVE TO CHECK FOR DUBLICATES B/W J & K SEPEREATELY INSIDE THE WHILE LOOP:
        vector<vector<int>>res;
       
        if(nums.size()<3)
            return res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(i!=0&&nums[i]==nums[i-1])
                continue;
            int j=i+1,k=nums.size()-1;
           
            while(j<k)
            {
            //CHECKING FOR DUBLICATES B/W J& K
            if(j>i+1&&j<k&&nums[j]==nums[j-1])
            {
                while(j<k&&nums[j]==nums[j-1])
                    j++;
                continue;
            }
                    
                if((nums[j]+nums[k])==(-nums[i]))
                {
                    vector<int>pair;
                    pair.push_back(nums[i]);
                    pair.push_back(nums[j]);
                    pair.push_back(nums[k]);
                    res.push_back(pair);
                    j++;
                    k--;
                }
                else if((nums[j]+nums[k])<(-nums[i]))
                {
                    j++;
                }
                 else if((nums[j]+nums[k])>(-nums[i]))
                 {
                     k--;
                 }
               
            }
           
        }
        //res.erase(unique(res.begin(), res.end()), res.end());
         return res;
    }
};
