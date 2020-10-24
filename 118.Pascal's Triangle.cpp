//DAY 2 PROBLEM 1
//The idea is to use the previously calculated rows for computing the current row i.e. dynamic programming
//🤮🤮Do not access 2d vectors ans by indexes like ans[i][j] in vectors of vectors before initialising the vectors, it gave me error since hours
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=0;i<numRows;i++)
        {
            vector<int>vec;
            
            for(int j=0;j<=i;j++)
            {
               
                if(i==j||j==0)
                    vec.push_back(1);
                else
                    vec.push_back(ans[i-1][j]+ans[i-1][j-1]);   
            }
            ans.push_back(vec);
        }
        return ans;
    }
};
