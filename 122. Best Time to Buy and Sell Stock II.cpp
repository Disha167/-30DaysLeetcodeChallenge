//🎯DAY 71 PROBLEM 2
/*You can buy and sell as many times you want, so here PEAK-VALLEY CONCEPT comes to picture. You can both buy & sell at the same day, so you can buy & sell 
everytime the adjacent next price is greater than the present.

If you will make a graph for the prices like 1 7 8 10, then the differences between the consecutive numbers 7-1=6, 8-7=1, 10-8=2 all will sum up to 6+2+1=9=10-1
always so you can add the differences everytime.


The peak valley concept goes like this:
1
\       3   /5   
 \     /\  /
  \   /  \/
   \ /   4
    2
  HEIGHT (2,3)+HEIGHT(4,5)>=HEIGHT(2,5)
  
  There cant be a possible value of stocks where this is not true because how much the stocks will go down from 3 to 4, this much it will go up and extra will be 
  height(4,5)-height(3,4) so we have this diff extra in L.H.S , it can't be less .
  
  
*/

/*yaha pr key ye hai ki hum atmost 1 hi share hold krskte hai toh humko 
    jitna difference milta jaye utna grab krna hai
    
    Eg: 
    1st case: we have 4>2 but 4<7
    2 4 7 isme 7-2=5 hai toh 4-2 + 7-4 = 5 hai
    2nd case: isme 1<2 1<3
    2 1 3 isme 3-1=2 hai
    3rd case: isme 5>2 but 5<3
    2 5 3 isme 5-2=3 hai ans 
    toh all possible cases me, whatever profit we are getting , we will add it up*/

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
