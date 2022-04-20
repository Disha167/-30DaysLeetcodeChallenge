//🎯DAY 16 PROBLEM 2
//The idea is to apply binary search for two parts of the array seperately, after determining the pivot point.
//Just remember the case when the pivot point is the last element i.e. eg. 1 2 3 4 5 so we have to appply binary search on whole array seperately.. as arr[i]>arr[i+1] will
never be true.

class Solution {
public:
    int binarySearch(int l, int r,vector< int> arr,int target)
    {
        if(l<=r)
        {
        int mid= l+ (r-l)/2;
        if(arr[mid]==target)
            return mid;
        if(arr[mid]>target)
            return binarySearch(l,mid-1,arr,target);
        if(arr[mid]<target)
            return binarySearch(mid+1,r,arr,target);
        }
        //l becomes equal to r only when the target is not found  
        return -1;
    }
    int search(vector<int>& nums, int target) {
        if(nums.empty())return -1;
        if(nums.size()==1) return (nums[0]==target)?0:-1;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i<nums.size()-1&&nums[i]>nums[i+1])
            {
                return max(binarySearch(0,i,nums,target),binarySearch(i+1,nums.size()-1,nums,target));
          
                }
        }
        
        return max(binarySearch(0,nums.size()-1,nums,target),-1);
    }
};

/*In the above approach, still to find the pivot. we have to do linear time search that makes the time complexity O(n) so then applying binary search 
makes no sense, so we use a O(logn) approach . First we find out which part of array is sorted, after finding this you can easily check that whether the
target is present in this part or not.
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0, end=nums.size()-1;
        int index=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            // cout<<mid<<" "<<nums[mid]<<" ";
            if(nums[mid]==target)
            {
                // cout<<"ams"<<endl;
                return mid;
            }
            /*CHECK IF LEFT PART IS SORTED*/
            if(nums[start]<=nums[mid]) //!!!IMP!!! Dont forget to put = between nums[start] and nums[mid] as when nums[start] & nums[mid] are equal,
            //it will not go inside any of the conditions 
            {
                if(target>nums[mid]||target<nums[start])
                {
                    start=mid+1;
                }
                else 
                {
                    end=mid-1; //if it is present in the first half, we can do end=mid-1 as mid ko toh hum already check krke aaein hain
                }
                // cout<<"end: "<<end<<endl;
            }
            
            else /*IF RIGHT PART IS SORTED*/
            {
                if(target<nums[mid]||target>nums[end])
                {
                    end=mid-1;
                }
                else
                    start=mid+1;
            }
        }
        return -1;
    }
};


