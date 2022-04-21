//🎯DAY 83 PROBLEM 2
/* So, here you have to find the path having max sum, note that the path can also contain one node. So, on moving upward we return the lt+root as it can 
form a path ahead, similarly only root and rt+root. So, the rt and lt that we have at every step stores the max possible sum that can make the path
and can be extended. 
For considering the path, we have two choices either by including root or not including root.
But, at every step we have to also consider the path including the curr root, so at every step ans can be lt+curr_root->val,rt+curr_root->val,
lt+rt+curr_root->val, curr_root->val

*/
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
    int helper(TreeNode* root, int &ans)
    {
        if(root==NULL)
            return 0;
        int lt=helper(root->left,ans);
        int rt=helper(root->right,ans);
        ans=max({ans,root->val,root->val+lt+rt,root->val+lt,root->val+rt}); //remember here 1 node is allowed so answer can be root->val also. Lt & rt has 
      //already been updated in previous step when doing root->val+lt+rl for its child.
        return max({root->val,root->val+lt,root->val+rt});
    }
    int maxPathSum(TreeNode* root) {
        /*two choices-> finding the max path that includes the current node: one is to include that node & other is to not.
        If we are not including, then we take max of leftsum & rightsum.
        So, at every step, we take max of left_subtree+root,right_subtree+root,root & return it upwards.*/
        int ans=INT_MIN;
        helper(root,ans);
        return ans;
    }
};
