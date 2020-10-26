//DAY 4 PROBLEM 1
class Solution {
    
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>count;
      
        if(s.length()==0)//🚩🚩Wait,did you handle this?
            return 0;
        int low=0,high=0,ans=0,length_string=s.size();
        //🔊🔊key is to map the characters with their last occurences
         while(high<length_string)
         {
             if(count.find(s[high])!=count.end())
             {
             //😠 😠 to store the rightmost occurence
                 low=max(count[s[high]]+1,low);
             }
             count[s[high]]=high;
             
             ans=max(ans,high-low+1);
             high++;
         }
             
           
         
        return ans;
        
    }
};
