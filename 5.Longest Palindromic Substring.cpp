//DAY 6 PROBLEM 1
//Not used the dp solution. Looking for help if anybody has solved with lcs based approach.
class Solution {
public:
    //we use the fact that palindrome if the string length is even, then centered at space b/w letters and if odd spaced b/w letters
    //thus having n+1 such centers
int expand_from_center(string str,int start,int end)
{
    
    while(start>=0&&end<str.length()&&str[start]==str[end])
    {
        start--;
        end++;
    }
    return end-start-1;
}
    string longestPalindrome(string s) {
        if(s.size()==0)
            return "";
        int len=s.length(),max_len=0;
        string ans;
        for(int i=0;i<len;i++)
        {
            int len_odd=expand_from_center(s,i,i);
            int len_even=expand_from_center(s,i,i+1);
            int start=0,end=0;
            if(max_len<len_odd||max_len<len_even)
            {
                max_len=max(len_odd,len_even);
                start=i-((max_len-1)/2);
                end=i+(max_len/2);
                ans=s.substr(start,end-start+1);
            }
        }
         return ans;     
      
    }
};
