//🎯DAY 77 PROBLEM 1
/* This is a simple problem where we just have to keep track of freq and repeat the pattern inside the brackets that number of time. Eg : For input 2[a]g,
output will be aag. But, it might become a little trickier when we have a subproblem inside a problem for 2[s3[g]], answer would be sgggsggg.
So we use recursion as we have to solve all the subproblems in the same way as that of a problem, so a subproblem can be considered a problem in itself.
We just have to take care of updating the no_of_times and ans_string correctly as it will be different for every recursion call stack. 
*/

class Solution {
public:
    string helper(string s, int &i, string ans_string)
    {
         ans_string="";//for every new subproblem, ans_string starts from 0 & as we get a closed bracket then we return it to str. 
        int no_of_times=0; //for every new subproblem , the frequency is initialised with 0
        for(;i<s.size();i++)
        {
            if(isdigit( s[i])) 
                 no_of_times = no_of_times*10 + (s[i]-'0'); //we keep on adding it to our previous no_of_times for examples like 23[bc], we will update
          //no_of_times from 2 to 2*10+3=23
            else if(s[i]=='[')
            {
                 i++;
                 string str =helper(s, i, ans_string); //on encountering [, it will be a new subproblem and we will call the recursion func for it.
                 for(int j=0;j<no_of_times;j++)
                 {
                    ans_string+=str; //we keep on adding str to ans_string no_of_times, the ans_string changes with every rescursion call like for 
                  // 3[a2[c]], the ans_string was a in 2nd call, then str is returned from its child call to it as cc, then we add cc to a 3 no_of_times.
                   //so, then ans becomes accaccacc
                 }   
                 no_of_times=0;//after every end of bracket, we need to start with fresh no_of_times
            }
            else if(s[i]==']')
                return ans_string;
            
            else
                ans_string+=s[i];
            
        }
        return ans_string;//once i becomes >s.size(), then we return ans_string
    }
    string decodeString(string s) {
        int index=0;
        string string_to_be_repeated=""; 
        return helper(s,index,string_to_be_repeated);
    
    }
};
