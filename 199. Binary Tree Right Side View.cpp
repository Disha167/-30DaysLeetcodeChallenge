//🎯DAY 56 PROBLEM 1
//In this, we have to print the first node from right at each level, it can be done by level order traversal simply by storing the last node at each traversal or by 
//recurse traversal, by first going to right of tree, then left and storing the first node we come across at each level in ans vector. We maintain a variable for
//checking at which level we are currently.
class Solution {
public:
    int height(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        return max(height(root->left),height(root->right))+1;
    }
    void recurse(TreeNode* root,vector<int>&ans,int level, int height)
    {
        if(level>height)
            return;
        if(root==NULL)
            return;
        recurse(root->right,ans,level+1,height); //we first traverse to the right child because it is right view
        if(ans[level]==-1) //when the current level is one, then we update the value at the current index in vector
            ans[level]=root->val;
        recurse(root->left,ans,level+1,height);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans(height(root),-1);
        recurse(root,ans,0,height(root));
        return ans;
    }
};
//level-order traversal-> 
//In level order traversal, we go from left to right in each level so if we want right view, we keep on updating the current value of the vector because it will
//be the last node.
class Solution {
public:
    int height(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        return max(height(root->left),height(root->right))+1;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans(height(root));
        if(root==NULL)
            return ans;
       
        queue<TreeNode* >q;
        q.push(root); 
        int level=0;
        while(!q.empty())
        {
            int n=q.size(); 
            
            for(int i=0;i<n;i++) //when we finish iterating through the current level by for loop, then we had popped the current level from the queue and pushed the
              //next level in the queue laready that is why we take n=q.size() and for every element one for loop is run and that is pushed in the vector for
              //level order traversal
            {
                TreeNode* tp=q.front();
                q.pop();
                ans[level]=tp->val;
                if(tp->left) q.push(tp->left); //we dont need to check tp for null before checking tp->left because if tp would be null, the previous level would 
              //not have pushed it.
                if(tp->right) q.push(tp->right); 
            }
            level++;
        }
        return ans;
    }
};
