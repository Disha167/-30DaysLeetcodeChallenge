//🎯DAY 48 PROBLEM 1
//Interesting Problem
//Can be solved by brute force easily by making a recursion tree and on every step, the recursion will have 2 choices either to treat the current letter seperately or combine
//them with the previous letter i.e. on adding "1" to "1", there are two possibilities treating 1 seperately i.e. decoding will be AA & combining 1 with previous 1, it will be 
//"11" i.e. decoding K.But, the time complexity will be O(2^n)
//To improve on time complexity, we use dynamic programming i.e. store values. We store the number of ways to decode for the previous index and previous to previous index and then
//use it to compute the number of ways to decode for the current index.
//1)For, seperate letter if the letter is > 0, it can be used seperately in decoding i.e. on adding 2 to "111", the number of decoding considering 2 seperate will be 3:
//"1" "1" "1" "2"    AAAB
//"11" "1" "2"      KAB
//"1" "11" "2"      AKB
//In above examples, the ways of decoding "111" was 3 AAA,KA,AK, we have just appended B to all of them but when we insert 0 instead of one then no decoding would be possible
//considering 0 as a seperate letter.
//2)If we consider "2" combined with another letter, then for deciding the number of encoding possible, we have to check the number of ways for encoding "11" i.e. previous to
//previous index and then append 12 to all the ways i.e.:
//"1" "1" "12"   AAL
//"11" "12"      KL
//So, we just have to keep track to number of ways to decode for prev to prev letter & no. of ways to decode for prev letter and keep on updating them on every index
class Solution {
public:

    int numDecodings(string s) {
      
        if(s.empty()==true)
            return 1;
        if(s[0]=='0')
            return 0;

      int countprev=1,countprevprev=1;
        for(int i=1;i<s.size();i++)
        {
            int curr_count=0;
            int seperate_digit=(s[i]-'0');
            int combined_digit=(s[i-1]-'0')*10+d;
            if(seperate_digit>0) curr_count+=countprev;
            if(combined_digit>=10&&combined_digit<=26) curr_count+=countprevprev;//(A value>26 cannot be decoded to A-Z)
            countprevprev=countprev;//we keep on updating countprevprev & countprev as we increment i
            countprev=count;
        }
        return countprev;
    }
};
