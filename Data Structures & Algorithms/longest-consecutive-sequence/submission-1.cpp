class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        // create a set that will contain all the numbers of the nums array without duplicates
        unordered_set<int> numSet(nums.begin(), nums.end());
        // contains the result
        int longest = 0;

        for(int n: numSet) // for every number in numSet
        {
            // if the current num - 1 does not exist then this is the start of a new sequence
            if(numSet.find(n-1) == numSet.end())
            {
                int length = 1; // set the length of the new sequence to 1
                // then while the current number + the current length DOES EXIST in numSey
                // increment the length of the sequence
                while(numSet.find(n+length) != numSet.end())
                {
                    length++;
                }

                // find the max longest sequence
                longest = max(longest, length);
            }
        }

        return longest;
    }
};
