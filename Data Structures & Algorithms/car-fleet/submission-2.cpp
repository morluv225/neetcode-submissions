class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // create a vector to store the pairs of each car's position and speed
        vector<pair<int, int>> pair; 
        for(int i = 0; i < position.size(); i++)
        {
            pair.push_back({position[i], speed[i]});
        }

        // sort the array of pairs in decreasing order (reverse)
        // because we want to process the closest cars first
        sort(pair.rbegin(), pair.rend());

        // create a monotonic stack (one that keeps its elements in sorted order)
        // to track the time each fleet takes to reach the target
        vector<double> stack;
        
        for(auto& p: pair)
        {
            // calculate how long it will take each fleet to get to the target
            // and append to the stack
            double arrivalTime = (double)(target-p.first) / p.second;
            stack.push_back(arrivalTime);

            // Make sure that there are at least two cars on the road to compare against each other
            // And that the arrival time of the current car is less than or equal to the arrival time of the car ahead of it
            // If these are both true, then they merge into one fleet and we can remove the current car's time because it has caught up to the slower car
            // If the current car's arrival time is greater, than it cannot catch up and it forms a new fleet of its own
            if (stack.size() >= 2 && stack.back() <= stack[stack.size() - 2])
            {
                stack.pop_back();
            }
        }

        // The number of remaining times = number of fleets
        return stack.size();
    }
};
