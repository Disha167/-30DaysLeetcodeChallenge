//🎯DAY 81 PROBLEM 1
/*The approach is simple to reverse the k nodes and then everytime instead of connecting the tail to null, connect it to head of next linked list.
We can get the head of the next linked list by returning the prev when we are doing recursion and the tail of the linked list after recursion will be
the head of the linked list before recursion so that is stored in some variable and then recursion is called for next_ptr for next group of k nodes.
If the size of group is less than k, we dont have to do anything we just return the head of the next group with linked list order being as it is.

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
  ListNode* helper(ListNode* head, int k, int &length)
    {
        if(head==NULL) //base case
            return NULL;
        
        if(length>=k)/*this condition is necessary to check for not reversing the nodes when size<k*/
        {
            ListNode* curr=head, *prev=NULL, *next_ptr=NULL;
            int count=0;
            while(count<k)
            {
                next_ptr=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next_ptr;
                count++;
            }
            length-=k;
        
        /*This step is important after every reversal, let us say for 1->2 answer will be   2->1 and 1 will be connected to the rest of the part of linked list. So, we have the current head of the linked list (before reversal) in head so we connect the rest of the linked list to that only*/
        head->next=helper(next_ptr,k,length);
        /*prev will be the tail of linked list before reversal & that will be head after reversal ao we return it to attach it to prev linked list*/
        return prev;
        }
        else 
          return head;
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr=head;
        int length=0;
        while(curr!=NULL)
        {
            curr=curr->next;
            length++;
        }
        return helper(head,k,length);
    }
};
