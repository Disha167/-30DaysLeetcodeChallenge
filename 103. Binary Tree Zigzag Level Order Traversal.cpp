//🎯DAY 49 PROBLEM 1
//The idea is to use Level Order Traversal, and for every level if it is odd, then reverse the vector.
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>vec;
         if(root==NULL)
             return vec;
        vector<int>temp;
        temp.push_back(root->val);
        vec.push_back(temp);
        int index=0;
        while(!q.empty())
        {
            int count=q.size();
            for(int i=0;i<count;i++)
            {
                TreeNode* tp=q.front();
                 q.pop();
                if((tp!=NULL)&&((tp->left)!=NULL))
                    q.push(tp->left);
                if((tp!=NULL)&&((tp->right)!=NULL))
                    q.push(tp->right);
            }
            queue<TreeNode*>q2(q);
            vector<int>temp1;
            while(!q2.empty())
            {
                TreeNode* tp =q2.front();
                int val=tp->val;
                q2.pop();
                temp1.push_back(val);
            }
            if(index%2==0)
            {
                reverse(temp1.begin(),temp1.end());
            }
            index++;
            if(!temp1.empty())
            vec.push_back(temp1);
        }
        return vec;
    }
};
