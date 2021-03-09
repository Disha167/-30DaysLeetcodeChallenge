//🎯DAY 39 PROBLEM 1
//Binary Search On answer technique is used. Normally, we use binary search when we see a sorted array but this technique uses binary search for unsorted array as well.
//In binary search, at every step we reject half the portion of the array so here also we follow the same procedure but instead of the criterias if arr[mid]==key for returning
//and if(arr[mid]<key) for moving to right, we customise our criterias
class Solution {
public:
    int binarysearch(vector<int>nums, int low, int high)
    {
        while(low<=high)
        {
        int mid=low + (high-low)/2;
        if(mid==0&&(nums[mid]>nums[mid+1]))
            return mid;
        else if(mid==nums.size()-1&&(nums[mid]>nums[mid-1]))
            return mid;
        else if((mid>0)&&(nums[mid]>nums[mid-1])&&(mid<nums.size()-1)&&(nums[mid]>nums[mid+1]))
            return mid;
        else if((mid<nums.size()-1)&&nums[mid]>nums[mid+1])//We check on exact neighbours, if the next neighbour is lesser than the current element itself it can no way contribute
          //to peak element so we go to the left half of array
            high=mid-1;
        else 
            low=mid+1;
        }
        return -1;
        
    }
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)return 0;
       return binarysearch(nums,0,nums.size()-1);
    }
};
