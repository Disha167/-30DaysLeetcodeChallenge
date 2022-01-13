//🎯DAY 72 PROBLEM 2
/*The approach is simple.We have to reverse the words in the string so what we do is that we collect all the words seperately in a string & push each time in a 
vector. The curr_String is updated untill we get a space & similarly all the words are pushed into the vector. Then, reverse the vector & append all the strings of
vector orderwise in the answer string. */
class Solution {
public:
    string reverseWords(string s) {
        string str=s;
        vector<string>vec;
    for(int i=0;i<str.size();)
    {
        string curr_word="";
        if(str[i]!=' ')
        {
          /*i<str.size() is necessary to avoid infinite loop*/
            while(i<str.size()&&str[i]!=' ')
            {
                curr_word+=str[i];
                i++;
            }
            vec.push_back(curr_word);
        }
        
        else /*when there is space , then we just move forward without doing anything*/
        {
            i++;
        }

    }
  
    reverse(vec.begin(),vec.end());
    string ans="";
    for(int i=0;i<vec.size();i++)
    {
        
        ans+=vec[i];
      /*This is necessary edge case to deal with as you don't want a space after the last word , just you want spaces after the n-2 words, not n-1 word.*/
        if(i<vec.size()-1)
        ans+=" ";
    }
    return ans;

        
    }
};
