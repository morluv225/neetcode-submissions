class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // create the pri q and populate it with the points coordinates
        // and its distance from the origin. 
        // The max heap will determine which one is the largest by the distance from the origin
        priority_queue<pair<int, pair<int,int>>> maxHeap;
        for(auto& point:points)
        {
            int dist = point[0] * point[0] + point[1] * point[1];
            maxHeap.push({dist, {point[0], point[1]}});
            if(maxHeap.size() > k)
            {
                maxHeap.pop();
            }
        }

        vector<vector<int>> res;
        while(!maxHeap.empty())
        {
            // push the coordinate pair onto the result vector
            // and remove the pair from the heap
            res.push_back({maxHeap.top().second.first, maxHeap.top().second.second});
            maxHeap.pop();
        }

        return res;
    }
};
