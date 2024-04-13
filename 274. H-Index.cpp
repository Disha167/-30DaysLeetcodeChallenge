/*The goal of this question is to find the largest m such that we have atleast m numbers greater than m. So, for easily getting the count of numbers greater than a a particular
number for calculating the answer, we will sort the array. 
Note: It can also be solved linearly, not a very intuitive binary search question but can think of it to optimize
Then, we can apply binary search to find the value of m optimally, as we can always neglect one side of the array left or right and decide to move in one direction based on the
current number in an array
Eg:   0 1 2 5 6
Index 0 1 2 3 4
So start=0 end=4, mid = 0+4/2=2 we will check whether at 2nd index, we have an eligible h-index?, i.e. 2 so n-mid=5-2=3 so 2<3 it cannot be an h-index as we do not have 3 numbers that are
greater than 3, so we need to increase the citation so we will move towards right i.e. start++. 
Now, start=1 end=4, mid=1+4/2=3 at 3rd index we have 5, 5>=(5-3) or 5>=2 so there are two numbers i.e. greater than 2, so ans=2 for now. For optimising the answer, we will do end-- as we can 
find a more optimised answer at left i.e. comparatively greater vaue of n-mid as mid decreases.
Now start=1 end=3 mid=1+3/2=2, again start++
Now start=2 end=3 mid=3+2/2=2 again start++
Now start=3 end=3 mid=3 then end--
start>end and it comes out of loop*/



class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size()-1;
        sort(citations.begin(),citations.end());
       int start=0,end=citations.size()-1;
       int ans=0;
       if(citations.size()==1)
            return citations[0]?1:0;
       while(start<=end)
       {
        int mid=start + (end-start)/2;
        if(citations[mid]>=((end-mid)+1))
        {
            ans=max(ans,min(citations[mid],((n-mid)+1)));// imp to use n here as end value changes everytime and to get all numbers greater than current you will need fixed size
           
            end--;
        }
        else
        start++;
       }
       return ans;

    }
};
