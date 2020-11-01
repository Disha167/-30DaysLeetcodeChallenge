 //DAY 11 PROBLEM 1
 //Purely mathematical question
 //I deciphered the pattern that the cycle occurs for 4 number i.e. if we keep on squaring the digits of number 4 and adding them, we will encounter 4 again so
 //I have terminated my while loop at 4 to avoid time limit exceeded.
 //Another approach to use can be a set to keep a track of all the numbers already encountered and return false if a number repeats
 bool isHappy(int n) {
      
        if(n==1) return true;
                int rem=0;
        long long int sum=0;
        int processed_num=n;
        if(processed_num==4) return 0;
        while(processed_num!=4&&processed_num!=1)
        {
            rem=0,sum=0;
            while(n)
            {
            
            rem=n%10;
                //cout<<rem<<" ";
              sum=((sum+(rem*rem))>=INT_MAX)?-5:(sum+(rem*rem));
                if(sum==-5)
                    return false;
            n=n/10;
                }
            //cout<<endl;
           
            processed_num=sum;
             //cout<<"processed_num"<<processed_num<<endl;
            n=processed_num;
        }
        if(processed_num==1)
               return true;
        else
            return false;
    
    }
};
