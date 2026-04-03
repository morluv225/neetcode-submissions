class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        //hash map to store the index and the number associated with said index
        // Key = the integer value. Value = the index
        unordered_map<int, int> seen;

        for(int n = 0; n < nums.size(); n++)
        {
            // The number we're looking for is the target number minuse whatever number we're at in the array
            int numToFind = target - nums[n];
            if(seen.find(numToFind) != seen.end())
            {
                return {seen[numToFind], n}; // return the index of the numToFind and the current index
            }

            // update the map with the current array value and its index
            seen[nums[n]] = n; 

        }

        return {};
    }
};
