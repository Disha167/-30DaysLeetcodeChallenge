//🎯DAY 30 PROBLEM 1
//Here, there is an assumption that always it will reach the last index so no need to check whether it will reach the last index or not.
/*THE CONCEPT BEHIND THIS PROBLEM IS THAT FOR EVERY INDEX WE CALCULATE MAX_REACHABLE INDEX WHILE TRAVERSING FROM THE CURRENT MAX_INDEX IT CAN REACH,(WE JUST KEEP
ON DECREASING THE STEPS)
BEFORE GOING TO NEXT LEVEL I.E. MAKING A JUMP(WHEN STEPS BECOMES 0), WE MAKE STEPS=MAX_REACHABLE-I I.E. EQUIVALENT TO MAKING A JUMP FROM MOST OPTIMAL INDEX
(This is the simple trick!!)*/

//We try to compress the solution in O(n), we take 2 pointers and traverse through the array iteratively from 1 to (n-1)th index(0 based indexing). For eg, if we 
//take the array 1 2 5 1 1 1 1 0 1 . The two pointers will be maxReachable i.e. the maximum index that can be reached from a particular position, NoOfSteps possible
//to take from the current position and one AnsJumps for storing the minimum number of jumps to reach last index. We have used the greedy approach i.e. we keep 
//track of the maximum reachable index from the given index and maximum reachable will not change unless we get a more optimal i.e. less number of jumps to reach 
//the last index . Eg. we do not update maxReach after encountering 5 in the above array as jumping from 5 will directly make us reach us 7th index instead of 
//jumping 4 times through the 1s. And on reaching 0, i becomes equal to maxreachindex so we return -1 as we cannot go further from 0 (not a part of this ques 
//although as here it supposes we always reach)


//class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        int MaxReachable=nums[0];
        int AnsJumps=1;
        int NoOfStepsPossible=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(i==nums.size()-1)
                return AnsJumps;
            MaxReachable=max(MaxReachable,i+nums[i]);
            NoOfStepsPossible--;
            if(NoOfStepsPossible==0)
            {
                AnsJumps++;
                NoOfStepsPossible=MaxReachable-i;
            }
        }
        return AnsJumps;
    }
};
