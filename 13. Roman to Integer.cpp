//DAY 10 PROBLEM 1
class Solution {
public:
    int romanToInt(string s) {
     
        int res=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i+1]=='V'&&s[i]=='I')
            {
                i++;
                res+=4;
            }
            
            else if(s[i+1]=='X'&&s[i]=='I')
            {
                i++;
                res+=9;
            }
            
            else if(s[i+1]=='L'&&s[i]=='X')
            {
                i++;
                res+=40;
            }
            
           else  if(s[i+1]=='C'&&s[i]=='X')
            {
                i++;
                res+=90;
            }
            
            else if(s[i+1]=='D'&&s[i]=='C')
            {
                i++;
                res+=400;
            }
            
            else if(s[i+1]=='M'&&s[i]=='C')
            {
                i++;
                res+=900;
            }
            else if(s[i]=='I')
            {
                res+=1;
            }
              else if(s[i]=='V')
            {
                res+=5;
            }
              else if(s[i]=='X')
            {
                res+=10;
            }
              else if(s[i]=='L')
            {
                res+=50;
            }
              else if(s[i]=='C')
            {
                res+=100;
            }
              else if(s[i]=='D')
            {
                res+=500;
            }
              else if(s[i]=='M')
            {
                res+=1000;
            }
        }
        return res;
    }
};
