//🎯DAY 51 PROBLEM 1
//works for unsorted elements also to find the least window size to get sum atleast k
//if we know the exact sum then only hashing can be used
//this solution is based on sliding window technique i.e. we keep on adding the elements untill the sum is less than k , but once the sum becomes k, then we keep on subtracting 
//element i..e minimizing window size and hence keeping track of the length of the array.
//But, this method can't be used when the target sum is negative as this algorithm works because when we keep on adding elements, the sum increases but that is not true when we
//add negative elements(only works for positive elements)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
          int len=INT_MAX,presum=0,windowsum=0;
        int left=0,right=0;
        while(right<nums.size())
        {
            windowsum+=nums[right];
            while(windowsum>=target)
            {
                len=min(len,right-left+1);
                windowsum-=nums[left];
                left++;
            }
            right++;
        }
        if(len==INT_MAX)
            return 0;
        else
            return len;
    }
};


//it is a good problem to think of now once you get the approach that you have to keep on incrementing left pointer if the window is not valid, and if it is valid decrement the right
//pointer to optimise it
//But, you have to keep in mind that you have to do both of the things simultaneously i.e. you keep on incrementing and then decrement as soon as you find the solution in the same
//iteration otherwise your end value is messed if it is incremented it becomes end+1 and then you found the solution at end, so while find the solution only you have to optimise it
//so the logic is that keep on expanding the window right++/end++ and then for every valid expansion try to optimise it. It is NESTED WHILE LOOP
//SEGREGATION OF TWO LOGICS WILL NOT WORK AS ONE OF THE LOGIC OF EXPANDING THE WINDOW IS DEPENDENT ON ANOTHER
//ONCE YOU EXPAND THE WINDOW TO 5, AND YOU GET SUM AS TARGET THEN YOU HAVE TO OPTIMISE IT IN SAME ITERATION IT DOSEN'T HAVE TO GET OPTIMISED IN 6TH ITERATION OTHERWISE THE LOGIC BECOMES 
//FLAWED HERE IF,ELSE CANT BE USED BECAUSE BOTH HAS TO BE DONE AT THE SAME TIME .IN SAME ITERATION YOU HAVE TO INCREASE AND YOU HAVE TO OPTIMISE FOR EVERY ELEMENT AS END OF WINDOW
//WRONG SOLUTION
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start=0;
        int end=1;
        int min_ans=nums.size()+1,sum=nums[0];
        while(end<nums.size())
        {
            if(end<nums.size()&&sum<target)
            {
                while(end<nums.size()&&sum<target)
                {      
                    sum+=nums[end];
                    end++; 
                }  
            }
            else if(sum>=target)
            {  
                while(start<nums.size()&&start<end&&sum>=target)
                {            
                    min_ans=min(min_ans,end-start+1);
                    sum-=nums[start];
                    start++;  
                }   
            } 
            //agar ye uppar wale me ni jaraha that means ki sum target hochuka aur optimise hochuka hai toh fr break krdo
        }
        return min_ans;      
    }
};
