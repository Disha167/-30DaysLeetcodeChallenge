class Solution {
    /*
    
    Iska key ye hai ki agar answer exist krta hai toh unique hai, toh we have
    to just start considering every index as a negative index.
    Humko gas aur cost ke diff se mtlb hai, jaha diff negative hojata
    waha tk koi bhi point se hum start ni krskte toh hum i+1 se start krenge
    aur agar i+1 se start krne pr hum end tk pauhnch gye toh fr whi humara ans hai
    
     BASIC IDEA
    My logic is very simple, for every index what we are doing is calculating
    diff between gas and cost, and the answer will be to start at the index that has the highest value of prefix array( from right) of the difference*/
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0,fuel=0,total_diff=0;
        for(int i=0;i<gas.size();i++)
        {
            int curr_diff=gas[i]-cost[i];
            total_diff +=(curr_diff);
            fuel+=curr_diff;
            if(fuel<0) // yaha pr ye logic se horaha ki agar fuel(prefixsum) waha tk negative hai toh
            //waha tk kisi bhi point se start ni krskte... aur aage hume koi positive point milgya aur
            //usko lekr hum end tk jaskte hai toh whi answer hoga.. kyunki unique ans hai agar answer exist
            //krta hai toh , exist krta hai ya ni ye hum total gas kam hai cost se is se pta kr rahe pehle.
            {
                start=i+1;
                // cout<<start<<endl;
                fuel=0; //KYUNKI humko curr_diff ni chahiye jb fuel negative hai
            }
        }
        if(total_diff<0) return -1;
        return start;
        
        }
};
