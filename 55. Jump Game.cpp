class Solution {
    /*the logic of this question is we have to store the number of steps we
     can take from a index in the dp of that index, for every index we will 
     decrease one step as we are travelling to the next index and then store
     the value.
     We will take max of the value at current index and dp of previous index
     as number of steps it can go forward from that index. 
     
     Edge case will be when nums[i] itself is 0, then you dont have to take max,
     then you only have to store any value in dp of that index if we can
     reach to that index and will have some steps after reaching that is 
     dp[i-1]-1>0 otherwise dp[i] will be 0 and false will be returned.

     We will do this till index n-2, if we have dp[n-2]>=1 then we return true
     Generic edge case being size of nums is 1*/
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        int n=nums.size();
       vector<int>dp(nums.size(),0);
       dp[0]=nums[0];
       for(int i=1;i<nums.size();i++)
       {

        if((dp[i-1]-1)>=0)
            dp[i]=max(dp[i-1]-1,nums[i]);
        else/*you can also use nums[i]==0 condition here*/
            {
                if((dp[i-1]-1)>0)
                dp[i]=dp[i-1]-1;
                else
                {
                dp[i]=0;
                return false;
                }

            }
       } 
       if(dp[n-2]>=1)
       return true;
       else
       return false;
    }
};
