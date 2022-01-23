//🎯DAY 74 PROBLEM 1
/*A brute force approach is for every meeting find whether there is a end time that is lesser than the start time of the meet & then append the current meet to the 
same room . It will take O(n^2) approach. To optimise it, we need access to the meeting whose ending time is earliest, so that we can decide whether we can accomodate
the current meeting in that room. For that, we need to sort the meeting rooms on basis of their end time to decide whether or not to create a new room or let us
say we only want access to the earliest ending meeting & it should get updated everytime. So, we use a min heap to keep track of earliest ending meeting & proceed
on creating rooms similarly.*/
#include<bits/stdc++.h>
using namespace std;
int meetingRooms(int n, vector<vector<int>>& time){
    sort(time.begin(),time.end());
    priority_queue<int, vector<int>, greater<int> >minhp;
    minhp.push(time[0][1]);
    for(int i=1;i<n;i++)
    {
        int tp=minhp.top();
        if(tp<=time[i][0]) /*If the earliest ending meeting finishes, then that room is vacant & we can use it for our current meeting. Like if eg is              
        [2 5] [4 7] [6 9] [36,45], for 6,9 meeting room 2,5 will already be empty so no need to create another one. */
        {
            minhp.pop();
            minhp.push(time[i][1]);
        }
        else 
        {
            minhp.push(time[i][1]);
        }
    }
    return minhp.size();
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>time(n);
    for (int i = 0; i < n; i++)
    {
        int s,e;
        cin>>s>>e;
        time[i].push_back(s);
        time[i].push_back(e);
    }
    int ans = meetingRooms(n,time);
    cout<<ans;
}

/* 
Crio Methodology

Milestone 1: Understand the problem clearly
1. Ask questions & clarify the problem statement clearly.
2. Take an example or two to confirm your understanding of the input/output & extend it to test cases
Milestone 2: Finalize approach & execution plan
1. Understand what type of problem you are solving.
     a. Obvious logic, tests ability to convert logic to code
     b. Figuring out logic
     c. Knowledge of specific domain or concepts
     d. Knowledge of specific algorithm
     e. Mapping real world into abstract concepts/data structures
2. Brainstorm multiple ways to solve the problem and pick one
3. Get to a point where you can explain your approach to a 10 year old
4. Take a stab at the high-level logic & write it down.
5. Try to offload processing to functions & keeping your main code small.
Milestone 3: Code by expanding your pseudocode
1. Make sure you name the variables, functions clearly.
2. Avoid constants in your code unless necessary; go for generic functions, you can use examples for your thinking though.
3. Use libraries as much as possible
Milestone 4: Prove to the interviewer that your code works with unit tests
1. Make sure you check boundary conditions
2. Time & storage complexity
3. Suggest optimizations if applicable
*/
