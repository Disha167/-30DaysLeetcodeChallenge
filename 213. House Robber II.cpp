🎯DAY 87 PROBLEM 1
/*This problem is quite similar to house robber just the difference is that here the last and the first house cannot be robbed together, so what we can do
here is that calculate the maximum profit two times: one by excluding first one and by including last one. It will give maximum amount that can be robbed
including last one. Now , second time by excluding last one, it will give the maximum amount that can be robbed including first one
(or another approach is to maintain two coloums in array one profit excluding zero and another including zero, and then calculate on last index only for 
excluding zero coloumn, but the above method is doing the same thing essentially excluding zero when including last without maintaining 2 coloumns)*/
class Solution {
public:
    int rob(vector<int>& nums) {
  vector<int>dp(nums.size(),0);
        dp[0]=nums[0];
        if(nums.size()==1)/*to avoid segmentation fault*/
            return nums[0];
        if(nums.size()>1)
            dp[1]=max(nums[0],nums[1]);
        /*excluding last element*/
        if(nums.size()> 2)
        {
            for(int i=2;i<nums.size()-1;i++)
            {
                dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
            }
        }
        int exclude_last=dp[nums.size()-2];
        /*excluding first*/
        vector<int>dp1(nums.size(),0);
        dp1[1]=nums[1];
        if(nums.size()> 2)
        {
            for(int i=2;i<nums.size();i++)
            {
                dp1[i]=max(nums[i]+dp1[i-2],dp1[i-1]);
            }
        }
        int exclude_first=dp1[nums.size()-1];
        return max({exclude_first, exclude_last, nums[0], nums[nums.size()-1]});       
    
    }
};
