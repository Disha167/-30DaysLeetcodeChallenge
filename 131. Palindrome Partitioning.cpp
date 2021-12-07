/*We have to partition here in the string such that every substring we get is a palindrome, so we try to partition at every index, we have to update our start index
every time we make a partition & as we have to try through every index so we have to loop for the end_index over the whole string for every start index.*/
class Solution {
public:
    bool ispalindrome(string s, int start_index, int end_index)
    {
        int j=end_index;
        for(int i=start_index;i<=end_index&&i<=j;i++)
        {
            if(s[i]!=s[j])
                return false;
            j--;
        }
        return true;
    }
    void help(string s, int start_index, vector<vector<string>>&ans,vector<string>&curr_ans)
    {
        if(start_index==s.size())//if we have partitioned the whole string, the we push it back to our ans
        {
            ans.push_back(curr_ans);
            return;
        }
        
        for(int k=start_index;k<s.length();k++) //for every start_index, we have to try every index for the end_indexes of the string
        {
            if(ispalindrome(s,start_index,k))/*if the starting one is palindrome, then only you can partiton ahead*/
            {
                curr_ans.push_back(s.substr(start_index,k-start_index+1));
                help(s,k+1,ans,curr_ans); //as we have made our partition till k, then we call for k+1
                curr_ans.pop_back(); //if by any reason, it can't be partitoned further, then we have to pop the substring pushed at last & then try again for other
                                    //end indexes.
            }
        }
    }
    vector<vector<string>> partition(string s) {
        // int i=0,j=s.length()-1;
        vector<vector<string>>ans;
        vector<string>curr_ans;
        help(s,0,ans,curr_ans);
        return ans;
    }
};
