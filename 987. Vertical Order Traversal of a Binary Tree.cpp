/*In vertical order traversal, we just use the coordinate system & preorder or inorder or level order traversal. If our root has 0,0 coordinate .When we move left,
the row increases and the coloumn decreases by 1 and when we move right the row increases and the coloumn increases by 1 like in general for coordinate system.

                  1(0,0)
                /       \
           2(1,-1)      3(1,1)
           /     \         \
        4(2,-2)  5(2,0)    6(2,2)

Now, we can just push the coordinates in a map of map of multiset, and then just traverse to all coloumns and return the result.
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
    void inorder(map<int,map<int,multiset<int>>>&matrix,  TreeNode *root, int curr_row, int curr_col)
    {
        if(root==NULL)
            return;
        
        matrix[curr_col][curr_row].insert(root->val);//for (curr_col) every col, we traverse all the rows and return the ans.
        inorder(matrix,root->left,curr_row+1,curr_col-1);//by going left and down, row increases by 1 & col decreases by 1
        inorder(matrix,root->right,curr_row+1,curr_col+1);//by going right & down, row increases by 1 & col increases by 1
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>matrix;
       
        int curr_row=0,curr_col=0;
        inorder(matrix,root,curr_row,curr_col);
        vector<vector<int>>ans;
        
        for(auto it:matrix)
        {
          //for curr_col, print every element that is there in every row
           ans.push_back(vector<int>());
            for(auto p:it.second)
            {
                for(auto m3:p.second)
                {
                    // cout<<m3<<" ";
                    ans.back().push_back(m3);
                }
            }
         
            // cout<<endl;
        }
       
        return ans;
    }
};
