class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    
    unordered_map<int, int> map;

    for(int i = 0; i < nums.size(); i++)
    {
        int numToFind = target - nums[i];

        if(map.find(numToFind) != map.end())
        {
            return {map[numToFind], i};
        }

        map[nums[i]] = i;
    }

    return {};


    }
};
