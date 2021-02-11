//🎯DAY 33 PROBLEM 1
//This was a hard recursion problem, we have to generate all the combinations of the full binary tree possible.One possible optimisation is that the total number of nodes can 
//never be even as the full binary tree is made from full left binary tree and full right binary tree which all has even nodes and one root. So we form the tree recursively
//We form the left & right subtrees ranging from 1 to N-1 with all the odd numbers possible,  we store the results and then iterate through all the possible left and right 
//subtrees and keep on adding it to the result.
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
    vector<TreeNode*> allPossibleFBT(int N) {
        if(N==0) return {};
        if(N==1) return {new TreeNode()};//if n becomes one we just return one
     
        vector<TreeNode*>res;
        for(int i=1;i<N;i+=2)//to avoid even function calls, we use +2
        {
            vector<TreeNode*> left=allPossibleFBT(i);
            vector<TreeNode*> right=allPossibleFBT(N-i-1);
            for(auto l:left)
            {
                for(auto r:right)
                {
                    TreeNode* root=new TreeNode();
                    root->left=l;
                    root->right=r;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};
