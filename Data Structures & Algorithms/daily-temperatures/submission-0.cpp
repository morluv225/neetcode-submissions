class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       vector<int> res(temperatures.size(), 0);
       stack<pair<int,int>> stack; // stack to contain a pair {temp, index}

       for(int i = 0; i < temperatures.size(); i++)
       {
            int temp = temperatures[i]; // get the current temperature
            // while the stack isn't empty and the current temp is
            // greater than the temp on the top of the stack
            while(!stack.empty() && temp > stack.top().first)
            {
                auto pair = stack.top(); // get the current pair 
                stack.pop(); // remove it from the stack
                res[pair.second] = i - pair.second; // insert at that index the difference 
            }

            stack.push({temp,i}); // push the current temp and index pair onto the stack
       }

       return res;
    }
};
