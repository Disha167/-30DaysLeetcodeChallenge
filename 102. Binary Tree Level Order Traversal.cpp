//🎯DAY 54 PROBLEM 1
//In this question, we have to return the level order traversal of a binary tree in a 2d vector . It may be overlooked as an easy problem but it is not if did'nt recognized 
//the trick behind it. 
//MAIN IDEA IS TO KEEP NULL AFTER ROOT & AS SOON AS WE ENCOUNTER NULL, WE WOULD HAVE ONE LEVEL , THEN AGAIN PUSH NULL AFTER 1 LEVEL, THEN POP 1 LEVEL , THEN PUSH ANOTHER
//LEVEL AND NULL AFTER ANOTHER LEVEL. NULL IN Q WILL MARK ENDING OF EVERY LEVEL AND PUSH ALL THE CURRENT NODES IN OUR ANS VECTOR AS WE ENCOUNTER NULL THAT WILL SERVE AS
//OUR CURRENT LEVEL AND PROCESS GOES ON UNTILL Q IS EMPTY
//The idea used here is that push null at the end of root, and then whenever we get null then push another null in the queue. By the time,we will get null, then one level would
//have been already there in the queue ,SO we push null after one level like in below example 13,N will be there in q we pop 13,push 12 14 and then we pop null in next iteration
//then then 12,14 is already there in the q, then we push null. Then we pop 12, push 2,then pop 14, then again pop null & add the current level to our ans and push null after
//2 again, the 2 will be popped, then null will be popped and our current level 2 is added to our ans.
//           13
//          / \
//         12  14
//        /     
//       2       

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
       vector<vector<int>>final_ans;
        if(root==NULL)
            return final_ans;
       queue<TreeNode*> q;
        q.push(root);
        vector<int>ans;
        ans.push_back(root->val);
        final_ans.push_back(ans);
        q.push(NULL);
        ans.clear();
        while(!q.empty())
        {
            TreeNode* tp=q.front();
            q.pop();
          //we need to check whether q is empty before pushing null, as if there is no level in the queue then that means we have already processed all the nodes and
          //no need to add NULL again in the queue. Eg. for last level of above tree, if 13,N is there and we pop 13 out and then we push 12 and 14 in queue, then we pop null
          //out , then top of our queue is null & q is not empty, so we push null again now queue contains 12,14,N. Then, we pop 12 and add 2 in our queue, now queue contains
          //14,N,2. Then we pop 14 and it has no child  so we do nothing, then we pop N, and again push NULL in the queue. Then our queue contains 2,N. We pop 2, then we
          //don't do anything.Then, we pop NULL .Again, we go to if condition as top is NULL but q becomes empty this time so we don't push anything. So,This q empty
          //condition is necesarry to check otherwise we will keep pushing and poping null and go to infinte loop
            if(!q.empty()&&tp==NULL)
            {
                final_ans.push_back(ans);
                ans.clear();
                q.push(NULL);//we need to push null after every level.
                    continue;
            }
            else
            {
                if(tp!=NULL&&tp->left)
                {
                    ans.push_back(tp->left->val);
                    q.push(tp->left);
                }
                if(tp!=NULL&&tp->right)
                {
                    ans.push_back(tp->right->val);
                    q.push(tp->right);
                }
            }
        }
        return final_ans; 
    }
   
};
