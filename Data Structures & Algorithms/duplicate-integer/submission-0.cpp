class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        unordered_map<int, bool> map; // hash map to contain the integer value and a true/false whether it's been seen or not
        
        for(int i = 0; i < nums.size(); i++)
        {
            int target = nums[i];
            if(map.find(target) != map.end()) // if the current number is not in the map
            {
               return true;
            }
            else
            {
                map[nums[i]] = false;
            }
           
        }

        return false;
    }
};
