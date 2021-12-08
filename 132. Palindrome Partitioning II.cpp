/*We approach the problem in the same way as palindrome partitioning , we try to partition over the whole string for every starting index. And, we keep on returning 
the temp_min to the previous parent function call & then finally compare all the minimums for the 0th index.
*/
class Solution {    
public:
    
    bool ispalindrome(string &s, int index_start, int index_end)
    {
        int i=index_start,j=index_end;
        for(int i=index_start;i<=index_end;i++)
        {
            if(s[i]!=s[j])
                return false;
            j--;
        }
        return true;
    }
    
    int help(string &s, int index_start,  int temp_min, vector<int> &memoise)
        //we do not use & in temp_min as at every start_index, value of temp_min is different & we do not want temp_min's any index value to be the ans value,
      //rather ans is calculated only on 0th starting index
    {
         
        if(index_start>=s.size()-1)//no more partitions required
            return 0;
         if(memoise[index_start]!=-1)
         {
              return memoise[index_start];
         }
         temp_min=INT_MAX;
         for(int k=index_start;k<s.size();k++)
         {
            
             if(ispalindrome(s,index_start,k)) //only if the current substring is a palindrome, then we can partition further
             {
                 // curr_min++;
                int ans= (k<s.size()-1)+help(s,k+1,temp_min,memoise);
                 temp_min=min(temp_min,ans);
                 // temp_min--;
             }
         }
        return memoise[index_start]=temp_min; //after calculating the minimum partitions of the current starting index, i.e. coming out of the for loop, we store 
      //the temp_min in dp array.
    }
    int minCut(string s) {
        int temp_min=INT_MAX;
        vector<int> memoise(3000);
        fill(memoise.begin(), memoise.end(), -1);
        int ans=help(s,0,temp_min,memoise);
        return ans;
    }
};
