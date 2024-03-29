class Solution {
public:
/*tumko 2-3 edge case dimaag me rakhna hai jb rotate krte tym k=0 ho ya 1 
element hi ho ya toh rotate krke whi array aajaye aise...*/
    void rotate(vector<int>& nums, int k) {
        // int curr_process=nums[0], index=0;
        if(k==0||nums.size()==1||k==nums.size())
        return;
        if(k>nums.size())
        k=k%nums.size(); /*ek ye bhi testcase hai jisme nums ki size se zyada 
        rotate krna padta hai*/
        // for(int i=0;i<nums.size(); i++)
        // {
        //     if(index+k<nums.size())
        //     {
        //         int temp=curr_process;
        //         if((i>0)&&(index+k<nums.size())&&curr_process==nums[index+k])
        //         {
        //             index++;
        //             i--;
        //             cout<<"condition i--: ";

        //         }
        //         cout<<i<<" temp: "<<temp<<endl;
        //         curr_process=nums[index+k];
        //         nums[index+k]=temp;
        //         index=index+k;
        //     }

        //     else if((index-(nums.size()-k))<nums.size())
        //     {
        //         int temp=curr_process;
        //         if(i>0&&(index-(nums.size()-k)<nums.size())&&curr_process==nums[index-(nums.size()-k)])
        //         {
        //             index++;
        //             i--;
        //             cout<<"condition 2 i--: ";

        //         }
        //         cout<<i<<" temp: "<<temp<<endl;
        //         curr_process=nums[index-(nums.size()-k)];
        //         nums[index-(nums.size()-k)]=temp;
        //         index= index-(nums.size()-k);
        //     }

        // }
        //The above solution will pass 32/38 testcases
        //Below is another simple way to do it, it passes all test cases
        //Isko O(1) extra space me krne ka key ye hai ki array ko 2 parts me consider krna hai, reverse 1 part,then 2nd part jo ki O(n) me ho jaega then reverse the whole array
       //original array: 1 2 3 4 5 6 7 k=3 ans= 5 6 7 1 2 3 4
        reverse(nums.begin(),nums.end());// 7 6 5 4 3 2 1

        reverse (nums.begin(),nums.begin()+k);// 5 6 7 4 3 2 1
        reverse(nums.begin()+k,nums.end()); //5 6 7 1 2 3 4
        
    }
};
