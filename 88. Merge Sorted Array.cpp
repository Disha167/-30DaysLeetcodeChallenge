//🎯DAY 45 PROBLEM 1
//We follow the simple algorithm of insertion sort i.e for every element of nums2, we compare it with all elements of nums1 and keep on shifing the elements of nums1 to the 
//right untill it is greater than the curr element of nums2 making space for element of nums2 to get inserted. Once, we find the element smaller of equal to current element in
//nums2, we stop and insert the element.And, then again repeat the process for every element of nums2, starting from a non-zero element everytime.
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m==0) 
        { 
            for(int i=0;i<m+n;i++)
            {
                nums1[i]=nums2[i];
            }
            return;
        }
        int last_non_zero_index=m-1;
        for(int i=0;i<nums2.size();i++)
        {
            int j=last_non_zero_index; 
            if((j<m+n-1)&&nums1[j]>nums2[i])//to take care, to avoid out of bound error for index j, we check whether it is valid or not i.e. j<n+m-1 &&j>=0 for the while loop.
            {
                while((j>=0)&&(j<m+n-1)&&nums1[j]>nums2[i])
                {
                    nums1[j+1]=nums1[j];
                    j--;
                }
                nums1[++j]=nums2[i];
                j--;
                last_non_zero_index++;//as we insert one element on every iteration, the count of last_non_zero_index increases.
            }
            else if(j<m+n-1)
            {
               nums1[j+1]=nums2[i];
                last_non_zero_index++;
            }
            
        }
    }
};
