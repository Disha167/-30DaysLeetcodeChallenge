//DAY 6 PROBLEM 2
class Solution {
public:
    int reverse(int x) {
        if(x>=INT_MAX)
            return 0;
        string str=to_string(abs(x));
        int len=str.length()-1;
        int new_num=0,rem=0;
       
        while(x)
        {
            rem=x%10;
            //INT_MAX has a value of 2147483647 and it is possible that a 10 digit number
            //read from front is 1234567809 but on reversing gives a value greater than                 
            //INT_MAX and hence an overflow, so we also have to check overflow while                     
            //calculating new_num 
            if((new_num+rem*pow(10,len))>=INT_MAX||(new_num+rem*pow(10,len))<=INT_MIN)
                return 0;
            else
                new_num+=rem*pow(10,len);
            len--;
            x=x/10;
        }
        return new_num;
    }
};
