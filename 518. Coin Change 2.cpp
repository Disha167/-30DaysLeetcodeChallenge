//🎯DAY 77 PROBLEM 1
/*The question is very simple, dont complicate it. You have to give the total number of ways to collect change for a given amount. So, there are two choices for 
every coin, you can either take it or not take it. When you take it, then you will subtract the current value to get the remaining one but when you dont that
means you have processed the node and you decrease index, here j.
Every state of dp stores the total number of ways to reach the amount i using coins till jth index*/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(amount+1,vector<int>(coins.size()+1,0));
        for(int i=0;i<=amount;i++)
        {
            for(int j=0;j<=coins.size();j++)
            {
                if(i==0)
                    dp[i][j]=1;
                
                else if(j==0)
                    dp[i][j]=0;
                
                else if(coins[j-1]<=i)
                {
                    dp[i][j]=dp[i-coins[j-1]][j]+dp[i][j-1]; /*when you take the coin, the value i reduces by coins[j-1] but index j remains same as the current coin
                    can be taken again for making change but when it cant be processed first time, then index is reduced as it cant be processed any further.
                    We add both the ways to get the total number of ways.*/
                }
                else
                    dp[i][j]=dp[i][j-1];
                
            }
        }
        return dp[amount][coins.size()];
    }
};
