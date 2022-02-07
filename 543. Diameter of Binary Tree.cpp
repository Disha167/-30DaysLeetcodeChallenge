//🎯DAY 76 PROBLEM 1
/* Here, diameter is the number of edges between the largest path between two nodes. It can pass through any node.
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
int preorder(TreeNode* root, int &ans)
{
    if(root==NULL)
        return 0;
    int lf=preorder(root->left,ans);
    int rf=preorder(root->right,ans);
    ans=max(ans,lf+rf); //so if we include the node itself in the dia, then the diameter will be leftheight+rightheight
    return 1+max(lf,rf);//Also, if diameter is calculated through any other node then 1+max(leftheight,rightheight) will be passed to the function above.
   
   
}
int diameterOfBinaryTree(TreeNode* root) {
    int ans=0;
    preorder(root,ans);
    return ans;
    
   
}
};
