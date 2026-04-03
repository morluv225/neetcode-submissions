class KthLargest {
private:
    // declare the priority queue.
    // because a pri q is max_heap by default we have to override it to be a min heap
    // the data type, the container, and the comparator (defines the heap type)
    // if a > b, the a has less pri than b so b (the smaller element) floats upward
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int kVal;

public:
    KthLargest(int k, vector<int>& nums) {
        // assigning the constructor param to the member variable
        kVal = k;
        
        for(int num:nums)
        {
            // push every number on the heap
            // if the heap's size becomes greater than k
            // remove the top element
            minHeap.push(num);
            if(minHeap.size() > k)
            {
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        // the value needing to be added onto the heap
        // // if the heap's size becomes greater than k
        // remove the top element
        minHeap.push(val);
        if(minHeap.size() > kVal)
        {
            minHeap.pop();
        }

        // return the root of the tree which should be the kth largest element
        return minHeap.top();
    }
};
