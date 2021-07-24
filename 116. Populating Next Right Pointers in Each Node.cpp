//🎯DAY 56 PROBLEM 2
//The approach is very simple, to do a level order traversal and if it is not the last node in level order, then make curr->next=q.front() as when curr node is 
//popped out, root's right child is at the top of the queue. But, if it is the last node, then make it's next null.
class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return root;
        
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                Node* tp=q.front();
                q.pop();
                if(i<n-1)
                {
                    if(tp)
                        tp->next=q.front();
                }
                else
                    tp->next=NULL;
                if(tp->left) q.push(tp->left);
                if(tp->right) q.push(tp->right);
            }
        }
        return root;
        
    }
};
