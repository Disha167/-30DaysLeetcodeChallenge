//🎯 🎯 DAY 1 PROBLEM 2(Daily Challenge atleast 2 problems leetcode submit)
//🥵🥵Look for the corner cases in this question
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* head=NULL;
         ListNode* temp;
        int carry=0;
       while (l1||l2)
       { 
           //📌📌The NULL of l1 is checked i.e. if one linked list becomes NULL, then 0 is            
           //added instead of l1->val. l1->val will give exception error if l1 is NULL
           //😖😖Also, add the carry to the result before checking whether res/10>0
           //as if on adding carry also, it gives greater than 0, then we have to do 
           //res%10 for the answer linked list
           int res=(l1?l1->val:0)+(l2?l2->val:0)+carry;
           if(head==NULL)
           {
               head= new ListNode;
               head->val=(res>=10?res%10:res);
               temp=head;
               if(res/10>0) carry=res/10;
               
           }
           else
           {
               if(res/10>0)
               {
                   ListNode* nextptr=new ListNode;
                   nextptr->val=(res%10);
                   temp->next=nextptr;
                   carry=res/10;
               }
               else
               {
                   ListNode* nextptr=new ListNode;
                   nextptr->val=(res);
                   temp->next=nextptr;
                   carry=0;
               }
               temp=temp->next;
                   
           }
           if(l1) l1=l1->next;
          if(l2) l2=l2->next;
       }
        //😯😯Also, the answer linked list can exceed the length of two given linked lists 
        //i.e. (l and m where l>m )by 1, so for that condition check whether the last              
        //element in linked list i.e the first digit in number is >10 or not. If >10, then         
        //add another element in answer linked list for storing (l+1)th number
        if(carry>0)
        {
             ListNode* nextptr=new ListNode;
                   nextptr->val=carry;
                   temp->next=nextptr;
               
        }
            
        return head;
    }
};
