//🎯DAY 74 PROBLEM 2
/*another easy method would be to count the zeros and just append it */
/*USING 2 POINTER*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>arr=nums;
        	int zero=0;/*one pointer for finding the index of zero element */
	int next_non_zero=0;/*another pointer for traversing through the array and finding next non-zero element*/
	/*We want to shift all zeros to right, another way of saying this is push all non-zeros to left . So if tit is non-zero we skip it and if it is zero, then we swap it with the next non-zero element as the order of elements in zeros dosent matter.Every index is zero so it is a good appraoch
	*/
	for(int zero=0;zero<arr.size();zero++)
	{
		if(arr[zero]==0)
		{
            next_non_zero=zero;
			while(next_non_zero<arr.size()&&arr[next_non_zero]==0)
			{
				next_non_zero++;	
			}
            if(next_non_zero<arr.size())
			swap(arr[next_non_zero],arr[zero]);
		}
	}
        nums=arr;
        
    }
};
