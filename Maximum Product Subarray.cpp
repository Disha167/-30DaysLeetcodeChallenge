//🎯DAY 63 PROBLEM 1
//The presence of negative numbers in the array makes it a tricky question.
//For the negative numbers, we use the following approach , we keep a track of min_value uptill here and max_value uptill here and then for negative numbers, multiply
//the current digits both with min_value and max_value.
//IMP!!!!!!!!!! : We are saying here both min_value and max_value not like we multiply negative number with min_value always and positive number with max_value
//as we can get a even minimum number sometimes on multiplying current number with max_number so far.
//For eg.: in array -1 -2  -9  -6
//       max_so_far:-1  2  18  108
//       min_so_far:-1 -2 -18 -108
//Note that on 3rd min_so_far i.e -18, we did'nt got it by multiplying current number with prev min_so_far i.e. -9 with -2 rather we get min_so_far by multiplying 
//-9 with max_so_far 2. If we had taken min_so_far as -9 between 18 and -9, we would have got the wrong answer. That is the only tricky part to take care of in
//this question.
//So, we multiply all digits with min_val and max_val irrespective of wheter they are negative and positive.
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        int min_val=nums[0],max_val=nums[0];
       for(int i=1;i<nums.size();i++)
       {
           // if(i==1)
           // {
           //     dp[i]=max(dp[i],dp[i]*dp[i-1]);
           // }
           // else if(nums[i]<0)
           //     dp[i]=dp[i]*min_val;
           // else if(nums[i]>0)
           //     dp[i]=dp[i]*max_val;
           // else 
           //     dp[i]=nums[i];
           //we use nums[i]*max_val not nums[i]*dp[i-1] because max or min can be formed
           //without using dp[i-1]
            // dp[i]=max(dp[i]*max_val,dp[i]*min_val);
         //we need to make a temp variable to prevent max_val to be multiplied with nums[i] when calculating the min_val.
         //Otherwise , one number will be multiplied two times in one iteration.
               int temp=max_val;
           max_val=max(nums[i]*max_val,max(nums[i]*min_val,nums[i]));
         //So, we use nums[i[*temp here instead of nums[i]*max_val
           min_val=min(nums[i]*min_val,min(nums[i]*temp,nums[i]));
          ans=max({max_val,ans,temp,min_val});
       }
        return ans;
    }
};
