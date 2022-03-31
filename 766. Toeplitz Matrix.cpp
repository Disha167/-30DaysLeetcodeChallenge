//🎯DAY 77 PROBLEM 1
/*the only key here is that the absolute difference of all elements in the diagonal is same as all elements are at same distance from topmost row and 
leftmost coloumn*/
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        unordered_map<int,int>mp;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                int diff=i-j;
                if(mp.find(diff)==mp.end())
                {
                    mp[diff]=matrix[i][j];
                }
                else
                {
                    if(mp[diff]!=matrix[i][j])
                        return false;
                }
            }
        }
        return true;
    }
};
