//🎯DAY 73 PROBLEM 1
/*Very easy question, just remember that 2 pointers are used for accessing two parts of the array at same time. 1st pointer is used for deciding the index of 
original array.(Think of it as if we are creating a new array & maintaining elements there, then it would be easier) i.e. maintaining the indices of the final array
and 2nd pointer is used to count the element having frequency greater than dublicates & ignore them.
The first & the second pointer will never overlap as in the original array , we will have 2 options either to neglect the element or to copy so the first pointer 
count will be always behind the second pointer to calculate the frequency*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n<3)
        return n;
        int count=0;
        int index=0;
        /*one pointer can be maintained to keep the original index & other for counting the dublicates*/
        for(int i=0;i<n;)
        {
            if(i<n-2&&nums[i]==nums[i+1]&&nums[i+1]==nums[i+2])
            {
                int value=nums[i];
                nums[index]=nums[i];/*we copy the elements as 2 frequency is allowed*/
                nums[index+1]=nums[i+1];
                index+=2;
                i+=2;
                while(i<n&&nums[i]==value)
                {
                    count++;
                    // nums[i]=-1; /*the element has to be ignored just here, for that we use our second pointer to decide whether we have to ignore it or copy it*/
                    i++; 
                }
            }
            else 
            {

                nums[index]=nums[i];/*if the frequency is less than 2, then also the element has to be copied*/
                index++;
                i++;

            }

        }
        return n-count;
    
        
    }
};
