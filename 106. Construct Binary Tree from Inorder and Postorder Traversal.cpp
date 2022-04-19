//🎯DAY 76 PROBLEM 2
/*A unique binary tree can be constructed if postorder(LRO) and inorder(LOR) traversals of the tree are given. The logic is that in the postorder traversal for 
every subtrees, root always comes at the end, so we can find the root for every tree from postorder traversal. Now, to find the left and right of root, 
we can search that element in inorder traversal and the left of that element will be left subtree and right will be right subtree*/
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
/*Eg: 
INORDER:   40 20 50 10 60 30
POSTORDER: 40 50 20 60 30 10
      10
    /   \
   20    30
  /  \   /
40   50  60

Now , that we know the approach i.e. finding the last of all elements in postorder, it will be root and then finding the root in inorder. So, left of root
in inorder will be left subtree and right of root in inorder will be right subtree. And, we have to do recursion for every subtree so the problem is how
will the indexes of inorder and postorder will decrease. The inorder_start and inorder_end for left subtree will be inorder_start and root_index-1, for
right subtree it will be root_index+1 and inorder_end. For postorder, the indexes of the postorder_start and postorder_end will depend on the inorder,
it can be calculated on the basis of number of elements to the left of root. 20 40 50 are a part of left subtree i.e. present in first three index of 
postorder traversal so poststart=poststart and postend=poststart+nums_left-1 for left subtree and similarly 60 30 are a part of right subtree.
So, for right subtree, poststart=postart+nums_left and postend=postend-1.
*/
class Solution {
public:
    TreeNode* helper(vector<int>&postorder, vector<int> &inorder, unordered_map<int,int> &mp, int inStart, int inEnd, int postStart, int postEnd)
{
    if(inStart>inEnd||postStart>postEnd)
    return NULL;
    int inRoot=mp[postorder[postEnd]]; /*first we find the positon of the root in inorder, 10 is the last element of the postorder so it is the root. We find the
    position of 10 in inorder i.e. 4*/
    TreeNode* root=new TreeNode(inorder[inRoot]);
    int numsLeft=inRoot-inStart;/*Now numsleft means no of elements on the left of root i.e. here 4-0=4*/
     /*the left subtree will be 40,20,50 in inorder and 40,50,20 in postorder, inorder will be from 0 to 2 i.e. instart to inroot-1 and 
     postorder will be from 0 to 2 i.e.poststart(0) to postStart+numsleft-1 (0+3-1=2)*/
    root->left=helper(postorder,inorder,mp,inStart,inRoot-1,postStart,postStart+numsLeft-1);
     /*the right subtree will be 60,30 in inorder and 60,30 in postorder, inorder will be from 4 to 5 i.e. inroot+1 to inend and 
     postorder will be from 3 to 4 i.e. postStart+numsleft (0+3=3) to postend-1 (4)*/
    root->right=helper(postorder,inorder,mp,inRoot+1,inEnd,postStart+numsLeft,postEnd-1);
    return root;//now that the left and the right children of that tree is attached, we return root to it's parent
      /*Similarly, the recursion calls will be carried out for the left subtrees and right subtrees*/
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
    for(int i=0;i<inorder.size();i++)
    {
        mp[inorder[i]]=i;
    }
    TreeNode* root=helper(postorder,inorder,mp,0,inorder.size()-1,0,postorder.size()-1);
    return root;
        
    }
};
