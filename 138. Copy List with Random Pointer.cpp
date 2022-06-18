//🎯DAY 85 PROBLEM 1
/*Here we have to create a hard copy of brand new n nodes that has same numerical values as that of the previous list, and the new nodes should have same
same connection as that of previous list. 
THE APPROACH TO THIS PROBLEM IS
*/
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        unordered_map<Node* , Node*>mp;
        Node* new_head=NULL;
        while(temp)
        {
            Node* new_temp=new Node(temp->val);
            if(new_head==NULL)new_head=new_temp;
            mp.insert ({temp,new_temp});
            temp=temp->next;
        }
        temp=head;
        while(temp)
        {
          mp[temp]->next=mp[temp->next];
          mp[temp]->random=mp[temp->random]; 
          temp=temp->next;
        }
        return new_head;
    }
};
