//🎯DAY 52 PROBLEM 1
//The way of asking is different but it is the same problem as count the number of subsets with the given difference , here it is just asked in the way that before how many 
//elements we put- and before how many we put + but the problem is same. So, it reduces to subset sum problem just one very imp difference is that here the array element can
//be 0 as well 
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total_sum=0;
        for(int i=0;i<nums.size();i++)
            total_sum+=nums[i];
        //(total_sum-target)%2!=0 is very imp to be checked as if 23 is total_sum-target
        //then there is no way to divide the array into two equal sums..
        //the sum of two partitions can be 11, 12 or 12, 11 i.e. both sums would be
        //different
        if(total_sum<target||(total_sum-target)%2!=0)
            return 0;
        int given_sum=(total_sum-target)/2;
        int dp[given_sum+1][nums.size()+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<given_sum+1;i++)
        {
            for(int j=0;j<nums.size()+1;j++)
            {
                if(i==0&&j==0)
                    dp[i][j]=1;
                //we can directly give 1 when i==0 in subset sum problem as there can't 
                //be elements of subarrays as 0 but here it can be so we have to calculate
                //for i==0 now
                // else if(i==0)  //because sum 0 can also be formed from the array like in
                //[1,0] target=1 ans is 2
                //     dp[i][j]=1;
                else if(j==0)
                    dp[i][j]=0;
                else if(nums[j-1]<=i)
                    dp[i][j]=dp[i][j-1]+dp[i-nums[j-1]][j-1];
                else
                    dp[i][j]=dp[i][j-1];
            }
        }
        return dp[given_sum][nums.size()];
    }
};
