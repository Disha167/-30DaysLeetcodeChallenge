//without using substring
//sorry for the delay, struggling a little bit with my health and mental state
// will try to maintain consistency
//DAY 9 PROBEM 1
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        long long int org_x=x;
        long long int s=0;
      while(x)
      {
          int rem=x%10;
          s=s*10+rem;
         // cout<<s<<endl;
          x=x/10;
      }
        if(org_x==s&&org_x!=10)
            return true;
        else
            return false;
    }
};
