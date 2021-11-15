//🎯DAY 65 PROBLEM 1
/*So, in the question we have is to build a calculator to add and subtract and the thing that we have to think upon is how to deal with solving the equations in
the brackets first like here (1+(4+5+2)-3)+(6+8), so we make use of recursion i.e. whenever we see a bracket, then the whole expression from the opening to the
closing bracket is a whole new problem for us and we will solve it similarly by calling the help function again.*/

class Solution {
public:
    int help(string &s, int &i, int res,int sign)
    {
        sign=1,res=0;
        int num=0;
        while(i<s.size())
        {
            if(s[i]=='+') { res+=(num*sign); sign=1; i++; num=0;}
            
            else if(s[i]=='-') {  res+=(num*sign); sign =-1; i++; num=0;}
 /*We have to make num 0, after every operation + or -, but we cannot write num=0, before calculating the value of num as in test cases like 123, it will make
   num0 everytime before rendering a new digit and hence our final result will be only the last digit. In this case, only 3.*/
            else if(s[i]>='0' && s[i]<='9') {  num=num*10+(s[i]-'0'); i++;}
/*We have to make res 0 before calculating a new operation but we cannot write res=0 before calling the help function again as res will have our record of previous
value , in this case 1 so when we will calculate (4+5+2) i.e. 11 and return it then, 11 would be added in previously calculated 1 and then 12-3 will be evaluated
but if we make res 0 before calling , then res will not keep track of previous value and we will get wrong answer.*/
            else if(s[i]=='(') {i++; num=help(s,i,res,sign); i++;}
            
            else if(s[i]==')') { res+=(num*sign); return res; }
            
            else {i++;}
        }
        res+=(num*sign);
        return res;
    }
    int calculate(string s) {
        int res=0;
        int i=0,sign=1;
        int ans= help(s,i,res,sign);
        return ans;
    }
};
