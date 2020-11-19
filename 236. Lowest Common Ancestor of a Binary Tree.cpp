//DAY 9 PROBLEM 2
//using recursion, the idea is to keep track of the left and the right search values while performing the inorder traversal.If the root equals to any of the two nodes given, 
//return the node otherwise return NULL to the values of left search and right search.
//If the values of left search and right search, both are non-null, then we got our ans else we keep returning the non-null values upwards
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
   
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
            return NULL;
        if(root==p||root==q)
            return root;
        TreeNode* leftNode=NULL;
        TreeNode* rightNode=NULL;
       leftNode=lowestCommonAncestor(root->left,p,q);
        rightNode=lowestCommonAncestor(root->right,p,q);
        if(leftNode&&rightNode)
            return root;
        
        
           
        else if(leftNode==NULL&&rightNode==NULL)
            return NULL;
        else if(leftNode||rightNode)
         return leftNode?leftNode:rightNode;
        else
            return NULL;
    }
    
};
