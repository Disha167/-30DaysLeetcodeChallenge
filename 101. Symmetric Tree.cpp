//🎯DAY 49 PROBLEM 1
//To check symentricity, it has to be checked in two ways one structurewise and another valuewise . It can be done by storing the inorder traversal in a vector and check that 
//whether it is a palindrome but it fails in many of the cases like for eg.  5 4 1 null 1 null 4 2 null 2 null 
//                                          5
//                                       /    \
//                                     4        1
//                                    / \      / \
//                                null   1  null   4
//                                     /   \     /   \
//                                   2    null  2   null
//
//then the inorder traversal for above tree would be   -1 4 2 1 -1 5 -1 1 2 4 -1(if we take -1 for null)
//so if we see, the above will be a palindrome but it is not a smentric tree. So, we recursively check for evey left subtree and right subtree
//3 conditions will be formed:
//1)if both root of left subtree and root of right subtree is null, then it is symentric
//2)if one of them is null other is not, we always return false i.e. covered in default condition at last in our recursive solution.
//3)If both of them is not null, then first we check if value fo the roots are same, if not return false but if it is same, then we check further:
//that left node of right subtree should be equal to right node of left subtree & vice versa by two function calls in our recursive function.
class Solution {
public:
bool helper(TreeNode* t1,TreeNode* t2){
 
    if(t1==NULL&&t2==NULL)
        return true;       //if both is null, it is symentric
    else if(t1!=NULL&&t2!=NULL)
    return (t1->val==t2->val)&&helper(t1->left,t2->right)&&helper(t1->right,t2->left);//it will check first value, then by recursive call, check for left node of right subtree
  //and right node of left subtree
    
    return false;//by default if one subtree's root is null and 1 is not, it returns false
}
    
bool isSymmetric(TreeNode* root) {
 if(root==NULL)
     return true;
 bool result=true;
 bool ans=helper(root->left,root->right);
  return ans;  
    }
};
