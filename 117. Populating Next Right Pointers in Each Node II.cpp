//🎯DAY 57 PROBLEM 1
/*
Approaching by level order traversal is pretty easy, you just have to make next of the queue's top(and then pop it) to next queue's top.
It is tough when you have to do it in constant space, so here we follow an arbitrary approach of travelling the top to bottom(we can use leftmost node of each level
and change parent to leftmost node before updating the leftmost node of next level) by outer loop and travelling all the nodes from left to right by inner loop.

The approach is based on the trick that the ith level's next should be connected before traversing the (i+1)th level next.We make use of the ith level's next pointer
to access the next neighbour of the (i+1)th level.Eg we make use of 2's next neighbour 3 for accessing the next neighbour of 4 i.e. 5 
   1
  / \
 2   3
/     \
4      5

*/
Node* connect(Node* root) {
        
        Node  *parent=root,*childhead=NULL,*child=NULL;
        while(parent!=NULL)
        {
        //we travel through all the nodes of the current level from left to right by using parent's next pointer and then update the parent to childhead for 
          //travelling top to bottom when parent becomes null
            while(parent!=NULL)
            {
                if(parent->left!=NULL)
                {
                    if(childhead==NULL)
                        childhead=parent->left;//the leftmost non-null node is maintained in childhead
                    else
                        child->next=parent->left;
                    child=parent->left; //for maintaining the rightmost node of the current level in child pointer
                }
                
                if(parent->right!=NULL)
                {
                    if(childhead==NULL)
                        childhead=parent->right;
                    else
                        child->next=parent->right;
                    child=parent->right;
                }
                
                parent=parent->next;
            }
            parent=childhead;
            child=childhead=NULL;
        }
        return root;
    }
