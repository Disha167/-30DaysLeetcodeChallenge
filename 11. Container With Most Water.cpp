//DAY 8 PROBLEM 1
// Learnt about the two pointer approach, sliding window is a subset of two pointer technique.
//We use this technique when we have to compare each element with every element in the given collection.
//We use two pointer technique when we have to maintain two different parts of array at same time like here, we maintain the start bound as well as end bound of container
//We start from the two end points of the array, and decrease the pointer having lesser height untill both pointer becomes the same.
class Solution {
public:
    int maxArea(vector<int>& height) {
        //Two pointers will be used as we keep the track of two indices of the array at
        //every step and we use the pointer technique to eliminate the shorter height                
        //everytime as we have to find the maximum area and maximum height will give max. area
        int start=0;
        int end=height.size()-1;
        int max_area=0;
        while(start<end)
        {
            max_area=max(max_area,min(height[start],height[end])*(end-start));
            if(height[start]<height[end])
            {
                start++;
            }
            else
                end--;
        }
        return max_area;
    }
};
