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
