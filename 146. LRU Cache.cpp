//🎯DAY 59 PROBLEM 1
//In this, we use doubly linkedlist for maintaining the LRU cache, i.e. when we perform get or put on a node, it becomes most recently used so we delete the node
// at it's previous position (we find the previous position by using the map's key mp[key] gives the address of the node whose key is given to us) and then
//insert it after head as it is most recently used and then finally inserting it in the new position after head: to show that it is most recently used and using
//this current address to insert it into map again(deleting the previous address with same key earlier)
//Ease of deletion/insertion in doubly linked list is used here & ease of searching elements in map is used here
class LRUCache {
public:
    class ListNode {
        public:
            int key;
            int val;
            ListNode* next;
            ListNode* prev;
            ListNode(int _key, int _val)
            {
                key=_key;
                val=_val;
            }
    };
    map<int,ListNode*>mp;
    int _cap;
      ListNode* head=new ListNode(-1,-1);
      ListNode* tail=new ListNode(-2,-2);
    LRUCache(int capacity) {
      
        head->next=tail;
        tail->prev=head;
        _cap=capacity;
    }
    void add_node_after_head(ListNode * new_node)
    {
            
            ListNode* head_next=head->next;
            head->next=new_node;
            new_node->prev=head;
            new_node->next=head_next;
            head_next->prev=new_node;
           
    }
    void delete_node(ListNode* node)
    {
        ListNode* node_prev=node->prev;
        ListNode* node_next=node->next;
        node_prev->next=node_next;
        node_next->prev=node_prev;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
           
            ListNode* res_node=mp[key]; //we return the value if it is there in the map, but we also have to make it the most recently visited node so we have to 
          //delete it's current occurence & add it after head.
            delete_node(res_node);
            mp.erase(key);
            int val=res_node->val;
            ListNode* new_node=new ListNode(key,val);
            add_node_after_head(new_node);
            mp.insert({key,new_node});
            return res_node->val;
        }          
        else
            return -1;
    }
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
           
            delete_node(mp[key]); //if it is already there in the map, we delete the current occurence & insert it as most recently visited after head
             mp.erase(key);
        }
        if(mp.size()==_cap)
        {
            mp.erase(tail->prev->key); //if cache has already reached it's capacity then we have to remove the least recently used i.e. before tail & then insert 
          //the current key,value pair
            delete_node(tail->prev);
            
            
        }
       
            ListNode* new_node=new ListNode(key,value);
            add_node_after_head(new_node);
             mp.insert({key,new_node});
     
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */