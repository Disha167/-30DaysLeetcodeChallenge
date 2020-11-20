//DAY 10 PROBLEM 1
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    if(strs.empty()==true)
        return "";
    if(strs.size()==1)
        return strs[0];
    int flag=0;
   string ans="";
        
   for(int j=0;j<strs[0].size();j++)//we have to use strs[0].size() here... we cannot use untill flag==0 as in case of longest common prefix of ["flower","flower"], flag 
   //never becomes 0.
   {
      if(strs[j]==""&&j<strs.size()) 
          break;
      
       char x=strs[0][j];

       for(int i=1;i<strs.size();i++)
       {
           if(strs[i][j]==x)
           {
               if(i==strs.size()-1)
                  ans+=x;
           }
           else
           {
               flag=1;
               break;
           }
       }
       if(flag==1)
          break;
   }
 return ans;
    }
};
