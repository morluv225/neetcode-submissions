class Solution {
public:
    int jump(vector<int>& nums) {
    
        int n = nums.size();
        int jumps = 0;
        int currentEnd = 0;
        int maxJump = 0;

        for(int i = 0; i < n-1; i++)
        {
            maxJump = max(maxJump, i + nums[i]);

            if(i == currentEnd)
            {
                currentEnd = maxJump;
                jumps++;
            }
        }

        if(currentEnd >= n-1)
        {
            return jumps;
        }

        return jumps;
    }
};
