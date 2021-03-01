 //🎯DAY 37 PROBLEM 1
//Leetcode premium question so I have run it on geeksforgeeks ide in c code
//The algorithm suppose that every node has four properties instead of three i.e. also it's parent can be accessed
//And, mind that it only works for binary search tree, not for any binary tree.
//                20
//               /  \
//              8    22
//             / \
//            4   12
//               /  \
//             10    14
//There is a pattern needs to be observed that is the only key of solving this problem, if any node has a right subtree then we return the minimum value i.e. leftmost node in
//right subtree eg. the inorder successor of 8 is leftmost value of right subtree i.e. 10 and if any node does not have a right subtree, then go up untill you see a node
// i.e. left child of its parent
#include <stdio.h>
#include <stdlib.h>
 
/* A binary tree node has data, 
   the pointer to left child
   and a pointer to right child */
struct node {
    int data;
    struct node* left;
    struct node* right;
    struct node* parent;
};
 
struct node* minValue(struct node* node);
 
struct node* inOrderSuccessor(struct node* root, struct node* n)
{
    if(n->right!=NULL)
    return minValue(n->right);
    else
    {
        struct node* p=n->parent;
        while(n!=NULL&&p->left!=n)
        {
            n=p;
            p=n->parent;
        }
        return p;
    }
    return NULL;
    
}
 
/* Given a non-empty binary search tree, 
    return the minimum data  
    value found in that tree. Note that 
    the entire tree does not need
    to be searched. */
struct node* minValue(struct node* node)
{
    struct node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}
 
/* Helper function that allocates a new 
    node with the given data and 
    NULL left and right pointers. */
struct node* newNode(int data)
{
    struct node* node = (struct node*)
        malloc(sizeof(
            struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
 
    return (node);
}
 
/* Give a binary search tree and 
   a number, inserts a new node with    
    the given number in the correct 
    place in the tree. Returns the new
    root pointer which the caller should
    then use (the standard trick to 
    avoid using reference parameters). */
struct node* insert(struct node* node,
                    int data)
{
    /* 1. If the tree is empty, return a new,
      single node */
    if (node == NULL)
        return (newNode(data));
    else {
        struct node* temp;
 
        /* 2. Otherwise, recur down the tree */
        if (data <= node->data) {
            temp = insert(node->left, data);
            node->left = temp;
            temp->parent = node;
        }
        else {
            temp = insert(node->right, data);
            node->right = temp;
            temp->parent = node;
        }
 
        /* return the (unchanged) node pointer */
        return node;
    }
}
 
/* Driver program to test above functions*/
int main()
{
    struct node *root = NULL, *temp, *succ, *min;
 
    // creating the tree given in the above diagram
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 22);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 14);
    temp = root->left;
 
    succ = inOrderSuccessor(root, temp);
    if (succ != NULL)
        printf(
            "\n Inorder Successor of %d is %d ",
            temp->data, succ->data);
    else
        printf("\n Inorder Successor doesn't exit");
 
    getchar();
    return 0;
}
