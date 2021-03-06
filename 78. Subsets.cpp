//🎯DAY 41 PROBLEM 1
//We keep on going deep in the tree, using the index variable in stack calls, keep on adding the next next element like for nums=[1,2,3] , we add 1, add {1} to ans, then call for 
//index=1, add 2, curr becomes {1,2}, add it to ans, then call for index =2, then curr becomes {1,2,3}, add it to ans, then we have exhausted till nums.size()-1 so we backtrack
//by popping out 3, then {1,2} remains in our current and we don't have any choice except 3, so we backtrack more, pop 2, then curr becomes {1}, then we use the for loop i++
//occurs and then we add 3 to the curr, curr becomes {1,3}, we add it to our ans and so on.
class Solution {
public:
    void helper(vector<int>&nums,int index,vector<vector<int>>&ans,vector<int>curr)
    {
        //ans.insert({nums[index]});
       // vector<int>temp=curr;
       // temp.push_back(nums[index]);
        for(int i=index;i<nums.size();i++)//This for loop is for the time when helper returns it's control, we pop the ith character & then add the remaining characters by for loop
            //eg: removing the current charcter 2 then exploring the other options like adding 3 to previously present 1 in curr thus getting {1,3} if my nums is {1,2,3} .
        {
            curr.push_back(nums[i]);
            ans.push_back(curr);
            helper(nums,i+1,ans,curr); //this recursive call fixes the ith character & call for remaining characters of string
            curr.pop_back();//we backtrack i.e. explore the option when we had not taken ith character in our string
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        ans.push_back(curr);
     helper(nums,0,ans,curr);
        return ans;
    }
};
