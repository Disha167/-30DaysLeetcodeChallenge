//🎯DAY 72 PROBLEM 1
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int res=0;
        /*first edge case- when the size of nums is 0, then the first missing positive number is 1.*/
        if(nums.size()==0)
            return 1;
        for(int i=0;i<nums.size();i++)
        {
            /*another edge case is number after swapping & before swapping should be different*/
            /*And, our answer will be in range of 1 to nums.size()*/
            while(nums[i]>=1&&nums[i]<=nums.size()&&nums[i]!=nums[nums[i]-1])
            {
                int temp=nums[i];
                nums[i]=nums[nums[i]-1];
                nums[temp-1]=temp;
            }
        }
        int i,flag=0;
        /*Another edge case is that if all the numbers from 1 to n are present, then the res will not be 0 , instead it would be n+1.
        So, for that we make a flag as 0 & if all the nums[i] is i+1, then that means all numbers are present so we return n+1*/
         for(i=0;i<nums.size();i++)
        {
           if(nums[i]!=i+1)
           {
               flag=1;
               res=i+1;
               break;
           }
        }
        /*edge case*/
        if(flag==0&&res==0)
            return nums.size()+1;
        return res;
    }
};
