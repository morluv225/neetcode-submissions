class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26,0); // initialize an array with 26 elements with 0
        for(char task: tasks)
        {
            count[task - 'A']++; // count the frequency 
        }

        priority_queue<int> maxHeap; // use a priority queue to represent a maxheap(same functionality)

        for(int cnt:count)
        {
            if(cnt > 0)
            {
                maxHeap.push(cnt); // pushes the character frequencies onto the max heap(ordered by largest number)
            }
        }

        int time = 0;
        queue<pair<int,int>> q; // queue to track the character freq and the time it will take to add it back to the heap
        while(!maxHeap.empty() || !q.empty()) //while the queues are not empty
        {
            time++; // increment the time

            if(maxHeap.empty())
            {
                time = q.front().second; // get the time interval that's been pushed onto the heap
            }
            else
            {
                //reduce the character frequency and remove the old frequency 
                int counter = maxHeap.top() - 1;
                maxHeap.pop();

                //if there are still more of the character left to process
                // aka the frequency is greater than 0. Push the new frequency and time onto the heap
                if(counter > 0)
                {
                    q.push({counter,time+n}); // push the new count and time onto the tracking q
                }
            }

             // if the q is not empty and the second element is the same value as the time
            if(!q.empty() && q.front().second == time)
            {
                maxHeap.push(q.front().first); // push the the new character frequency onto the maxHeap
                q.pop(); //pop the old frequency count and time
            }
        }

        return time;
    }
};
