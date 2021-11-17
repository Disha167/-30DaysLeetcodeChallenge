//🎯DAY 66 PROBLEM 1
/*The approach to this question is very logical, we need to find the median of running stream of numbers that means first there will be 1 integer,we need to find
the median of 1 and then if another no is added, we need to find the median of 2 and so on. The median is the middle element in the sorted array so if we have
to find the median of Eg. 1 2 3 4 , it will be (sum of 3 and 4 )/2 so we need access to the two middle elements for 1 2 3 4 5, the median will be 3 so we need
access to the middle element, so we can maintain 2 structures where the 1st structure will give access to the first middle element and 2nd structure to 2nd middle
element. We will use max heap & min heap, max heap for storing the first middle element i.e. the largest element in the first half of sorted array, max heap is used
as it gives access to the largest element and in the 2nd half min heap is used as we want the smallest element from 2nd half.*/
/*Another point to keep in mind is that the max difference between the sizes of two priority queues should be 1 as we need the middle element of the array, so if
in 1 2 3 4 5, first pq will store 1 and another pq wil store 2 3 4 5, then we will have access to 1 and 2 as top of both priority queues, but we need 3 for
calculation of the median. */
class MedianFinder {
public:
    priority_queue<int>max_heap;
    priority_queue<int,vector<int>,greater<int>>min_heap;
    MedianFinder() 
    {
        while(!max_heap.empty())
            max_heap.pop();
        while(!min_heap.empty())
            min_heap.pop();
    }
   
    void addNum(int num) 
    {
        if(max_heap.empty()||num<max_heap.top()) /*if the coming element is less than the max of 1st heap, then it needs to be in the first half of the element*/
        {
            max_heap.push(num);      
        }
        else /*otherwise, it needs to be in the other half*/
            min_heap.push(num);
        if(max_heap.size()>min_heap.size()+1)/*if the size of max_heap is more than min_heap +1 , i.e. it has extra elements so we pop from max_heap and push to 
        min_heap.*/
        {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        if(max_heap.size()+1<min_heap.size())
        {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian() 
    {
        if(max_heap.size()==min_heap.size())
            return (double(max_heap.top())+double(min_heap.top()))/2; /*if both have same size, that means the size of array is even then the median is sum of 2 
            middle elements*/
        else if(min_heap.size()>max_heap.size())/*otherwise, whoseover heap's size is larger will contain the median*/
            return min_heap.top();
        else
            return max_heap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
