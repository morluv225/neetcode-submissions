class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> seen;

        for(int n =0; n < nums.size(); n++)
        {
            int numToFind = target - nums[n];
            if(seen.find(numToFind) != seen.end())
            {
                return {seen[numToFind], n};
            }

            seen[nums[n]] = n;

        }

        return {};
    }
};
