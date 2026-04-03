class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];

        // need to store dp[n-1] and dp[n-2]
        // my choice are either dp[n-1] or nums[i] + dp[i-2]

        vector<int> dp(nums.size());
        dp[0] = nums[0]; // put the first element in the first spot
        dp[1] = max(nums[0], nums[1]); // gind tha max between the first two elements and store

        for(int i = 2; i < nums.size(); i++) // iterate through the rest of the array
        {
            // for the rest of the elements, fill them with the maximum of n-1 and n + n-2
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]); 
        }

        return dp[nums.size()-1]; // return the last element that should be the maximum amount of money.
    }
};
