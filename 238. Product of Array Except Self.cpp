class Solution {
    /*
    1 -2 3 -5
    1 0 2 0 4
    1 0 9 2 3
    */

/*
The key of this question is to think what all can affect the product/division of two nos and change it from simple calculation: p=abs(num1)/abs(num2).
1)IF any one number is negative, it can change the product from p to -p
2)IF num1 is 0, then p=0 and num2 cannot be 0.

So, idea is to take the total_product of array and keep on dividing it with current number to get the answer, for the 2nd edge case mentioned above we need to take a 2nd product in 
case we have one zero in our array to keep a track of product of rest of the numbers except 0. If either of the number or product is of opposite sign, then p will also be negative
and if number is 0, then we assign p to second_product calculated above keeping edge case i.e. one zero and rest numbers in mind

*/
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int total_product=1,second_product=1;
        int count_of_zero=0;
        for(int i=0;i<nums.size();i++)
        {
            total_product=total_product*nums[i];
            if(nums[i]!=0)
            second_product=second_product*nums[i];
            else
            count_of_zero++;

        }
        if(count_of_zero>1)
        second_product=0;

        vector<int>ans;
        
        for(int i=0;i<nums.size();i++)
        {
            int curr_ans=1;
            if(nums[i]!=0)
            curr_ans=abs(total_product)/abs(nums[i]);
            if(nums[i]<0)
            {
                
                if(total_product>0)
                {
                    curr_ans=curr_ans*-1;
                }   
            }

            else if(nums[i]>0)
            {
                if(total_product<0)
                curr_ans=curr_ans*-1;
            }
            else if(nums[i]==0)
            {
                
                curr_ans=second_product;

            }
            ans.push_back(curr_ans);

        }
        return ans;
    }

};
