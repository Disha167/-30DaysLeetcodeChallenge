class Solution {
public:
/*

quality|  /
       | /
       |/_________
       quantity

      1) humko ye 45 degree ki line ke paas laana hai, agar quantity kam hai mtlb lowerside me hai toh quanity badhaenge mtlb left me move kro
       taaki 45 degree tangent line ke paas jaye.. 
       citations[i] quality hai n-mid quantity
       citations[i]>=n-mid hai toh hum end=mid-1 left me jaenge
      2) agar quality kam hai toh mtlb upperside me hai toh hum right me move krenge array me taaki wo 45 degree line ke paas aaye mtlb ratio
       quality/quantity badh jaye kyunki array increasing order me hai toh
       citations[i] quality hai, agar ye kam hai toh start=mid+1 right me jane keliye
*/

    int hIndex(vector<int>& citations) {
        int n=citations.size()-1;
        sort(citations.begin(),citations.end());
       int start=0,end=citations.size()-1;
       int ans=0;
       if(citations.size()==1)
            return citations[0]?1:0;
       while(start<=end)
       {
        int mid=start + (end-start)/2;
        if(citations[mid]>=((n-mid)+1))
        {
            ans=max(ans,min(citations[mid],((n-mid)+1)));
            cout<<mid<<" "<<ans<<endl;
            end=mid-1; /*citations[mid] mtlb quality hai toh agar bada hai quality toh hum quantity badhaenge mtlb left me search krenge
            */

           
        }
        else/*idhar humari quantity zyada hai toh hum right me jaenge kyunki
        hume quality badhana hai aur array increasing order me order me sorted hai*/
         start=mid+1;
       }
       return ans;

    }
};
