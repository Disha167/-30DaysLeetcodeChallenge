//🎯DAY 75 PROBLEM 1
/*For O(n) extra space, we use supporting stack for keeping the track of minimum element . The normal stack Stck does the push and the pop operation.  */
class MinStack {
public:
      stack<int> SS , Stck;
    MinStack() {
      
        
    }
    /*We have to always push to the normal stack, but we push to the supporting stack only if the top of supporting stack is >= the element to be pushed.
    = is imp as the min of one range can bes ame as min of another range*/
    void push(int val) {
        int x=val;
         Stck.push(x);
        if(SS.empty())
        {
            SS.push(x);
        }
        else 
        {

            if(!SS.empty()&&SS.top()>=x)
            SS.push(x);
        }
        
    }
    
    void pop() {
      /*We pop from supporting stack only if it's top is same as main stack*/
         if(!Stck.empty())
    {
        if(!SS.empty()&&SS.top()==Stck.top())
        SS.pop();
    Stck.pop();
    }
        
    }
    
    int top() {
        return Stck.top();
    }
    
    int getMin() {
      /*min is stored in supporting stack so we return it's top*/
        if(!SS.empty())
        return SS.top();
    
    else
    return -1;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
