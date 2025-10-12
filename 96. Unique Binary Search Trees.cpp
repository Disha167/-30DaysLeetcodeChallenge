//This is a very interesting question : it involves permutation concept as well as recursion . The trick here is that you need to solve for 2 and then you need to break every problem into smaller problems and here 
//comes recursion. So, you have to think of this question as considering for every node as root, and then once you have considered root solve for left subtree and right subtree similarly.
//Just, one catch is there if there is 0 node so it is still one type of permutation and then all the permutation on left can be combined with all permutations on right so total no of permutations is multiple of both

class Solution {
public:
    int noOfPossiblePermutation(int noOfNodes)
    {
        if(noOfNodes<=2) 
        {
            if(noOfNodes==0) return 1;
            else
            return noOfNodes;
        }
        int ans=0;
        for(int val=1;val<=noOfNodes;val++)
        {
            //taking val as root
            int noOfLeftNodes=(val-1);
            int no_of_left_per=noOfPossiblePermutation(noOfLeftNodes);
            int noOfRightNodes=(noOfNodes-val);
            int no_of_right_per=noOfPossiblePermutation(noOfRightNodes);
            ans=ans+(no_of_left_per*no_of_right_per); 
            // cout<<val<< " "<<ans <<endl;
        }
        return ans; 
    }
    int numTrees(int n) {
        if(n<=2) return n;
        int ans=0;
        return noOfPossiblePermutation(n);
        // return ans;
    }
};
