//🎯DAY 71 PROBLEM 2
/*You can buy and sell as many times you want, so here PEAK-VALLEY CONCEPT comes to picture. You can both buy & sell at the same day, so you can buy & sell 
everytime the adjacent next price is greater than the present.

If you will make a graph for the prices like 1 7 8 10, then the differences between the consecutive numbers 7-1=6, 8-7=1, 10-8=2 all will sum up to 6+2+1=9=10-1
always so you can add the differences everytime.
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        for(int i=0;i<prices.size()-1;i++)
        {
            if(prices[i+1]>prices[i])
                profit+=(prices[i+1]-prices[i]);
        }
        return profit;
    }
};
