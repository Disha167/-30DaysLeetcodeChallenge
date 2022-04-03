//🎯DAY 78 PROBLEM 1
/*Here, in this question we need to use the 4 digits in any sequence with any of 4 operations between them to get 24, if it is possible then return true
else false. We can put parenthesis anywhere between the digits eg: if cards: 4 1 8 7, then (4-1)+(8-7) is also valid and 4-(1+8)-7 is also valid so the 
sequence of numbers dosen't matter, from this we get that we can take any two numbers in any order and then perform +,-,* or / between them.
SO, THE APPROACH WILL BE SIMILAR , we need to keep every number at each position & every operation between all permutations. We use two for loop
for using ever possible pair and then another for loop for all possible operations.
We use recursion call for the following:
Also, the new result that we perform by those two numbers will act as a new number in our vector(i.e. why the cards change) and then it will be used to
perform further operations.
Eg for 4 1 8 7 , once we perform 4+1=5 then 5 will be used to perform operations further 5+8=13 then 13+7 and so on.. untill vector is more than size 1.
For performing other operations -,* we backtrack and then iterate over all possible choices of operations.

*/
class Solution {
public:
    
    vector<double> evaluate(double a, double b)
    {
        return {a+b,a-b,a*b,a/b};
    }
    /*choices available: for every number, four operations & with every number*/
    /*NO NEED FOR THIS AS ADDING BRACKET JUST MEANS THAT ANY NUMBER CAN BE OPERATED WITH ANY NUMBER IN ANY SEQUENCE, THAT WE DO IN OUR FUNCTION ALREADY:
(once sequence generated , one function will check for all places to add bracket and calculate result)*/
    void helper(vector<double>cards, bool &ans)
    {
        if(cards.size()==1)/*as soon as the size of cards become 1, we check for 24*/
        {
            if(abs(cards[0] - 24) < 0.0001) /*we are checking 0.0001 due to double answer*/
            {
                ans=true;
                return;
            }
        }
        
        for(int i=0;i<cards.size();i++)
        {
            for(int j=0;j<cards.size();j++)
            {
                if(i==j)
                    continue;
                 vector<double>operations=evaluate(cards[i],cards[j]);/*here, we get the result of all operations +,-,*,/ and then iterate over each one 
                 of them: */
                for(int result=0;result<4;result++)
                {
                    curr_cards.clear();
                    curr_cards.push_back(num);
                    for(int k=0;k<cards.size();k++)/*we can also pop ith and jth card & then push_back num, but there was coming some segmentation fault.
                    So, we create a new empty vector and instead of popping, we just push the new ans & then push back all elements of cards as it is.*/
                    {
                        if(i!=k&&j!=k)
                        {
                            curr_cards.push_back(operations[result]);
                        }
                    }
                    helper(curr_cards,ans);/*cards vector changes in every stack call, on returning here(backtrack), we increase result i.e. explore other
                    operations and so on.*/
                }
            }
        }
     
        
    }
    bool judgePoint24(vector<int>& cards) {
      
        bool ans=false;
        vector<double>cards_list(cards.begin(),cards.end());
        helper(cards_list,ans);
        return ans;
    }
};
