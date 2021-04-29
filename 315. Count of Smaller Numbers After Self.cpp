//🎯DAY 50 PROBLEM 1
//finally done it
//was not able to do it earlier because was not understanding merge sort fully
//It uses the concept of merge sort, just adds j-mid for the count values.
class Solution {
public:
void merge(vector<pair<int,int>>&temp,vector<int>&ans,vector<pair<int,int>>&v, int l, int mid, int r)
{
    int start1=l,k=l,start2=mid;
    while(start1<=mid-1&&start2<=r)
    {
        if(v[start1].first<=v[start2].first)
        {
            temp[k]=v[start1];
            // by (j-mid) we calculate that how many elements from the second half is
            //already processed i.e. smaller than our current element and increase
            //the inversions for the element currently in first half
            ans[v[start1].second]+=(start2-mid);
            k++;
            start1++;
        }
        else 
        {
            temp[k]=v[start2];
          
            k++;
            start2++;
        }
    }
    while(start1<=mid-1)
    {
         temp[k]=v[start1];
      
        ans[v[start1].second]+=(start2-mid);
            k++;
            start1++;
    }
    while(start2<=r)
    {
        temp[k]=v[start2];
            
            k++;
            start2++;
    }
   //Also, at every return call of mergesort function, a sorted array is returned and we store the sorted array in temp as we have to use values of v to compare the values
  //but when returning to parent function, v is changed i.e. we make the v sorted. Eg for 5 3 2 4 1 ,  2 3 5 and 1 4 is returned to the parent function call and then the 
  //merge fucntion merges 2 3 5 and 1 4 arrays giving 1 2 3 4 5
    for(int i=l;i<=r;i++)
    {
      
        v[i]=temp[i];
    }

        return;
        
}
void mergesort(vector<pair<int,int>>&temp,vector<int>&ans,vector<pair<int,int>>&v,int l, int r)
{
    if(l<r)
    {
        int mid=l + (r-l)/2;
        mergesort(temp,ans,v,l,mid);
        mergesort(temp,ans,v,mid+1,r);
        merge(temp,ans,v,l,mid+1,r);
    }
}
vector<int> countSmaller(vector<int>& nums) {
vector<pair<int,int>>v(nums.size());
    for(int i=0;i<nums.size();i++)
    {
        v[i]={nums[i],i};
    }
    vector<int>ans(nums.size());
     for(int i=0;i<nums.size();i++)
    {
        ans[i]=0;
    }
    vector<pair<int,int>>temp(nums.size());
    mergesort(temp,ans,v,0,nums.size()-1);
    return ans;
}
};
