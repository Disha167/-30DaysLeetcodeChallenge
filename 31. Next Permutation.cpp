//🎯DAY 67 PROBLEM 1
//PATTERN OBSERVE KRNA IS THE KEY HERE
/*To build up the approach, if we start writing the permutations of 123456:
123456
123465
123546
123564
123645
123654
124365
  .
  .
And, so on so here what we are doing to obtain next permutation if you observe clearly from 123456 to 123465, jab hum permutation likhte hain tb hum aise
(hum last se dhundte hain kyunki hume pehle least significant bit manage krna hai)
sonchte hain ki agar last ka 2 element hi increasing order me sorted hai toh bauhat aasan hai bs swap krdo

Now, if we have to find next greatest no of 123465, ab last wala element toh descending me hai toh hum kya krte hain ki 1st pair aisa dhundo from end jo 
increasing order me ho kyunki 1 chhota element joki left me hai bade element ke usko hi swap krke bada no milega toh yahan pe 46 mtlb 4 ko swap krna hai
ab 6 se swap krenge toh 123645 pr hum 1235.. jaisa kuch bhi kr skte hain uske pehle toh fr hum 1st element dhundenge right se jo bada hai 4 se kyunki wo 
hi hume smallest element dega(4 smallest element ko ekdam rightest index pe pauhnchana hai number ekdam chhota bnane ke liye) , 4 ke baad ke elements
 decreasing order me hi honge humesha kyunki 123456 ko greater bnane ke liye already swap ho chuka hoga 123465 aise hi har case me..

toh 4 ko 5 se swap krke 123564 milega pr is se chhota bhi kuch ho skta toh 4 ke baad ke sb elements ko hum reverse kr skte.. kyunki smallest element
ekdam end me aagya hai



we find the first element from right that has the potential of swapping i.e it is in increasing order with next element so that on swapping we get a greater number like 4 here. Now for 
finding just the next greater, we find the first element from end that is greater than 4 to get just the next greater here it is 5, we think like this
that we swap a smaller element initially with a greater element at end, for finding next greater hum sbse peeche wale index ke saath khelenge, aur jab
hume ek baar swap krne ke liye 2 index mil jaega.. hume ye ensure krna hai ki us index ke baad ke saare element ascending order me rahein for just next 
greater. The same thing we apply to our solution.

*/
/*The solution is a 4-step process, the intuition can be obtained by writing all the dictionary orders, and then we will see a pattern in the numbers, that they are
always increasing from the end so we do, find index1->find index2->swap them->then reverse the remaining*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index1=nums.size()-1;
        /*Take example of 1 3 5 4 2*/
        for(int i=nums.size()-1;i>0;i--)
        {
            /*we need to find such a number that has a lesser value in left than right, that may have a potential for swapping to get the next permutation , 
            here 3*/
            if(nums[i-1]<nums[i])
            {
                index1=i-1;
                break;
            }
        }
         int index2=-1;
         for(int i=nums.size()-1;i>=0;i--)
        {
             /*Now, we get the first number from left that has greater value than nums[index1],as we want just the next permutation, so the least 
             significant bit from right will be most suitable, here 4*/
            if((i>index1)&&(nums[i]>nums[index1]))
            {
                index2=i;
                break;
            }
        }
        /*swap them to obtain a greater permutation*/
        if(index2!=-1)
        {
            swap(nums[index1],nums[index2]);
            /*Now, we have already made the value at index1 larger than the value in previous permutaion like in 1 3 5 4 2, after swapping 2 and 4,
            1 4 5 3 2 is always greater than the former number due to 4, no matter what is there after 4. And , for getting the just next greater permuation,
            we ensure the numbers after 4 to be in increasing order , so we reverse 5 3 2 as 2 3 5 and hence obtaining the ans 1 4 2 3 5*/
            reverse(nums.begin()+index1+1,nums.end());
        }
        else
            /*if the number is 5 4 3 2 1 and has no next permutation, then we return the smallest possible permutation 1 2 3 4 5*/
            reverse(nums.begin(),nums.end());
        
    }
};
