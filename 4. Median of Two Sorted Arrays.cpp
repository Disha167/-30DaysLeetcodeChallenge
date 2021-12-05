/*For median, we need the two middle elements of the array, so for the median of 2 sorted arrays combined, we need to partition both the arrays into two parts and 
eventually, for the new combined array, every half will have half the elements i.e.(n+m/2) if n is size of 1st array and m is the size of 2nd array.
So, we will try to explore every option of partition of 1st array, as 2nd array's partiton will depend on the way the 1st array has been partitioned.
We can find the median if we know how many elements from 1st array is coming to the first half, 
Eg: if arr1: 1 5 8 10 18 20 and arr2: 2 3 6 7 , then if we make cut1 from 1st index (as cut from 0th index is not possible, in worst case very half should have 10/2
5 elements), so 1 from arr1 and 2 3 6 7 from arr2 will be there in first half so median will have max of 1 and 7, and 2nd half will have 5 8 10 18 20 from 1st array
and infinite i.e. nothing from 2nd so median will have min of 5 and infinite. Now, the condition which we will use to decide which is the correct partiton is pretty
simple, now since the new array will be a sorted one so the extreme left that is largest element from 1st array's 1st half should be lesser than the smallest 
element of 2nd array's 2nd half and vice versa.
We can eliminate one half, if any of the conditions l1<r2 && l2<r1 is not satisfied so it is a question of binary search.
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size();
         /*as cut2 will be larger than cut1, so iterating cut2 over the larger nums makes more sense. Dry run over [2,3,4,5] [1]*/
        if(n1>n2)
            return findMedianSortedArrays(nums2,nums1);
       
        int lo=0, hi=n1;
        double median;
        while(lo<=hi)
        {
            int cut1=lo+ (hi-lo)/2;
            int cut2=((n1+n2)/2)-cut1; //if m+n/2=5 and we have taken 2 element from arr1 in 1st half, then we take 5-2=3 element from arr2 in 1st half.
           
            int l1=(cut1==0)?INT_MIN:nums1[cut1-1]; //largest element in arr1
            int l2=(cut2==0)?INT_MIN:nums2[cut2-1];//largest element in arr2
            int r1=(cut1==n1)?INT_MAX:nums1[cut1];//smallest element in arr1
            int r2=(cut2==n2)?INT_MAX:nums2[cut2];//smallest element in arr2
            
            if(l1>r2) //if largest element in 1st array is greater than smallest element in 2nd array, then we move towards left in arr1 to make largest element 
                      //smaller
            {
                hi=cut1-1;
            }
            else if(l2>r1)//if largest element in 2nd array is greater than smallest element in 1st array, then we move to right in arr2 to make the smallest 
                          // element in arr2 larger
                          
            {
                lo=cut1+1;
            }
            else //if both the conditons are satisfied, we have got our answer.
            {
                median=((n1+n2)%2==0)?(double(max(l1,l2)+min(r1,r2))/2.0):
                (min(r1,r2));
                return median;
            }
            
            
        }
       return -1; 
    }
};
