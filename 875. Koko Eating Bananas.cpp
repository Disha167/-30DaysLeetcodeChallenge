//🎯DAY 62 PROBLEM 1
//Painter partition type problem
//Binary search is applicable to this problem, as h is a monotonically decreasing function of k, i.e. as banana per hour eating speed k dereases, time taken i.e. h 
//increases whereas as k increases when h decreases.
//For binary search, we need a search space so low would be 0 i.e. speed can be minimum 0 (can't be negative) and high is sum of all bananas i.e. monkey can eat all
//bananas in 1 hr.
class Solution {
public:
    bool isfeasible(int mid, vector<int> &piles, int h)
    {
        int no_of_hours=0,curr=0;
        for(int i=0;i<piles.size();i++)
        {
            if(piles[i]<mid)
            { 
                no_of_hours++;
            }
            else
            {
                
                no_of_hours=no_of_hours+(piles[i]/mid);
                if(piles[i]%mid!=0)
                    no_of_hours++;
            }
            
            
        }
        if(no_of_hours<=h)
            return true;
        else
            return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long int sum=0;
        for(int i=0;i<piles.size();i++)
            sum+=piles[i];
        long long int start=0;
        long long int end=sum;
        long long int k=LLONG_MAX;
        while(start<=end)
        {
            long long int mid=start+(end-start)/2;
            if(mid!=0 && isfeasible(mid,piles,h)) //we need to check mid!=0 for avoiding the number to be divided by 0.
            //And, if a speed mid is feasible, all the speed greater than mid will be feasible for h hours, and we have to get the minimum possible speed, we move left 
            {
                k=k<mid?k:mid;
                end=mid-1;
            }
            else//if a speed mid is not feasible, then all speed lesser than mid is not, so we move to the right to increase the speed.
            //Just like binary search, we terminate half of our search space at every step.
                start=mid+1;
        }
        return k;
    }
};
