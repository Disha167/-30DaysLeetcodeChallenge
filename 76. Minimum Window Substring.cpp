//🎯DAY 40 PROBLEM 1
//Approach is to keep on expanding the end untill count does not reach t.size(), i..e we have not found all characters of t in our window. Once, we have found all characters 
//of t in our window, our aim is to minimize the window size , so we keep on incrementing the start untill the window becomes ineligible i.e. do not have all characters
//that are there in t. Everytime we do so, we update min_length to end-start+1 if curr window size is less than the minlength value.
class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()==0||(s.size()<t.size()))
            return "";
        if(s==t)
            return s;
         map<char,int>mp;
        for(int i=0;i<t.size();i++)
            mp[t[i]]++;
        int count_of_distinct_chars=0;
        int start=0,end=0,minleft=0;
        string ans="";
        int min_length=INT_MAX;
        while(end<s.size())
        {
            if(mp.find(s[end])!=mp.end())
            {
            mp[s[end]]--;
            if(mp[s[end]]>=0)
                count_of_distinct_chars++;
            }
            while(count_of_distinct_chars==t.size())
            {
               if(((end-start)+1)<min_length)
                {
                   min_length=(end-start)+1;
                   minleft=start;
                }
                if(mp.find(s[start])!=mp.end())
                {
                    mp[s[start]]++;
                    if(mp[s[start]]>0)
                       count_of_distinct_chars--;
                } 
                start++;
            }
            end++;
        }
        if(min_length!=INT_MAX)
        return s.substr(minleft,min_length);
        return "";
    }
};
