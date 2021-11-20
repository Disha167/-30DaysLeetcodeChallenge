//🎯DAY 67 PROBLEM 1
/*The solution is a 4-step process, the intuition can be obtained by writing all the dictionary orders, and then we will see a pattern in the numbers, that they are
always increasing from the end so we do, find index1->find index2->swap them->then reverse the remaining*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index1=nums.size()-1;
        /*Take example of 1 3 5 4 2*/
        for(int i=nums.size()-1;i>0;i--)
        {
            /*we need to find such a number that has a lesser value in left than right, that may have a potential for swapping to get the next permutation , 
            here 3*/
            if(nums[i-1]<nums[i])
            {
                index1=i-1;
                break;
            }
        }
         int index2=-1;
         for(int i=nums.size()-1;i>=0;i--)
        {
             /*Now, we get the first number from left that has greater value than nums[index1],as we want just the next permutation, so the least 
             significant bit from right will be most suitable, here 4*/
            if((i>index1)&&(nums[i]>nums[index1]))
            {
                index2=i;
                break;
            }
        }
        /*swap them to obtain a greater permutation*/
        if(index2!=-1)
        {
            swap(nums[index1],nums[index2]);
            /*Now, we have already made the value at index1 larger than the value in previous permutaion like in 1 3 5 4 2, after swapping 2 and 4,
            1 4 5 3 2 is always greater than the former number due to 4, no matter what is there after 4. And , for getting the just next greater permuation,
            we ensure the numbers after 4 to be in increasing order , so we reverse 5 3 2 as 2 3 5 and hence obtaining the ans 1 4 2 3 5*/
            reverse(nums.begin()+index1+1,nums.end());
        }
        else
            /*if the number is 5 4 3 2 1 and has no next permutation, then we return the smallest possible permutation 1 2 3 4 5*/
            reverse(nums.begin(),nums.end());
        
    }
};
