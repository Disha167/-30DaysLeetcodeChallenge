🎯DAY 86 PROBLEM 1
/*The approach is to use recursion, do the reversal of two adjacent nodes as the signature of the function, then at every pair suppose the adjacent nodes
are reversed. Then the attachment of the tail of the previous list to the head of current list can be performed as a part of induction step. At every 
recursion step, we can reverse the 2 nodes and attach the prev_tail to the new_head. The value of prev_tail can be tracked as a part of recursion call.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
   void swapNodes(ListNode* prev_tail,ListNode* temp)
    {
        if(temp==NULL)
            return ; 
 
        ListNode* next_node=temp->next;
        ListNode* next_next_node=NULL;
        if(next_node)
        {
            next_next_node=next_node->next;
            temp->next=NULL;/*The only step that is very imp is that after making the new reversed links, we also need to break the older links so that
            infinite loop is avoided. Eg: 1->2->3->4 after connecting 2->1 ,we also need to connect 1-> null otherwise it will result in a infinte loop*/
            next_node->next=temp;
            
        }
        if(prev_tail!=NULL)
        {
            if(next_node)
                prev_tail->next=next_node;
            else
                prev_tail->next=temp;
        }
     
        swapNodes(temp,next_next_node);
            
    }
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* temp=head;
        ListNode* new_head=temp->next;
        ListNode* prev_tail=NULL;
        swapNodes(prev_tail,temp);
        return new_head;
    }
};
