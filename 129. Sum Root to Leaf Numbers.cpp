//🎯DAY 60 PROBLEM 1
//This is a tree-traversal problem with basic concepts of recursion involved, we add the corresponding digit as we go down in the tree by inorder traversal and when it is a 
//leaf node, then sum value is updated 
//Eg:
//                 4
//                / \
//               9   0
//              / \
//             5   1
//
class Solution {
public:
//WORKING!!
//we pass currsum by value and not by reference because as shown in the previous example when the digit will go till 5 then the stack call will be inorder(5, 495,495), and 
//as it updates the sum value to 495 and backtracks then this stack call is over and is removed from the stack memory, then inorder(9,49,495) remains and the next
//stack call for 1 is done keeping currsum as 49 .
void inorder(TreeNode* root, int currsum,int &sum)
{
    if(root==NULL)
        return;
    currsum=(currsum*10) + root->val;
    if(root->left==NULL&&root->right==NULL) //once we get a leaf node, we update the sum variable with the digit formed untill now.
    {
        sum+=currsum;
        return;
    } 
    inorder(root->left,currsum,sum);
    inorder(root->right,currsum,sum);
 
}
int sumNumbers(TreeNode* root) {
    int n=0,sum=0;
    inorder(root,n,sum);
    return sum;
}
};
