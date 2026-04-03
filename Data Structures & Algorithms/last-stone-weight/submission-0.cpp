class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // build the maxHeap of all the stones
        priority_queue<int> maxHeap;
        for(int s:stones)
        {
            maxHeap.push(s);
        }

        // this is the smash loop
        // we want to loop until there's only one rock left on the heap
        // if x < y, we simply push the difference onto the heap
        // if x == y, we do nothing because the rocks are destroyed
        while (maxHeap.size() > 1)
        {
            int y = maxHeap.top();
            maxHeap.pop();
            int x = maxHeap.top();
            maxHeap.pop();

            if(x < y)
            {
                maxHeap.push(y-x);
            }
        }

        // if the Max Heap is empty then return 0, if its not, return the last stone
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};
