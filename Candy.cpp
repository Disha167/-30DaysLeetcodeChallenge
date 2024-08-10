class Solution {
    void num_of_candy_check(int index, vector<int> &ratings,vector<int> &ans)
    {
        if(index==0)
        {
            if(ratings[index]>ratings[index+1])
            {
                if(ans[index]<=ans[index+1])
                ans[index]=ans[index+1]+1;
            }
        }
        else if(index==ratings.size()-1)
        {
            if(ratings[index]>ratings[index-1])
            {
                if(ans[index]<=ans[index-1])
                ans[index]=ans[index-1]+1;
            }

        }
        else
        {
              if(ratings[index]>ratings[index+1])
            {
                if(ans[index]<=ans[index+1])
                ans[index]=ans[index+1]+1;
            }
             if(ratings[index]>ratings[index-1])
            {
                if(ans[index]<=ans[index-1])
                ans[index]=ans[index-1]+1;
            }
          /* 
          checking this will not work as this will only check this condition fo rnearest neighbours:
          eg: for 1 6 10 8 7 3 2
          after above conditions left to right for loop, they will get candies like this:
                  1 2 3  3 3 2 1
          that is wrong, as when we are increasing candy to index having higher ratings then their neighbours, then we dont just have to check the neighbours that rule is still being validated there. Thw whole line needs
          to be checked like when we updated for 3's rating, no of candy to2, we havge to update 7 as the 2nd rule gets violated and due to which 7's rule is also violating so more efficient way is to travel backwards once after assigning all candies from left to right, i.e. again we traverse right to left...
          As, we have validated 2nd rule for left to right already. While updating conditions for right neighbours, conditions for left neighbours are getting violated, eg when we update for 7 according to 3 then for 7-8 rules are not followed anymore so once we need to go from right to left as well       
          
           //order is important pehle index badha lena hai uske baad check krna hai ki rules toh violate ni horahe
            if(ratings[index]<ratings[index+1])
            {
                if(ans[index]>=ans[index+1])
                ans[index+1]=ans[index]+1;

            }

                if(ratings[index]<ratings[index-1])//dono condition true hoskti hai, else ni lagega
            {
                if(ans[index]>=ans[index-1])
                ans[index-1]=ans[index]+1;

            }*/

        }

    }
public:
    int candy(vector<int>& ratings) {
        if(ratings.size()==1) return 1;
/*key of the question is to check both of indexes not only for ki index ki rating zyada hai ya ni neighbours se.. but agar kam hai toh candy bhi kam mili hai na because when we move from left to right, sometimes the right
neighbour's no of candy although earlier less can become more on getting right and it should not be*/
        vector<int>ans(ratings.size(),1);
        for(int i=0;i<ratings.size();i++)
        {
            num_of_candy_check(i,ratings,ans);
        }
          for(int i=ratings.size()-1;i>=0;i--)
        {
            num_of_candy_check(i,ratings,ans);
        }
        int sum=0;
        for(int i =0;i<ans.size();i++)
        sum+=ans[i];
        return sum;
        
    }
};
//more optimised approach using O(1) space here: https://www.youtube.com/watch?v=YUT13Koh5Jg
