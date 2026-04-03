class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       sort(nums.begin(), nums.end()); // sort the integers in nums in order to set the pointers 
       vector<vector<int>> res; // result vector

       for(int i = 0; i < nums.size(); i++)
       {
            // if we're not at the first index and the prev number and current number are equal
            // we want to go to the next iteration and check if they're all the same number
            if(i > 0 && nums[i] == nums[i-1]) continue;

            // set the left and rigt pointers
            // l = i + 1 because we're going to use i as a pointer as well
            int l = i +1;
            int r = nums.size()-1;
            
            while(l < r)
            {
                int currentSum = nums[i] + nums[l] + nums[r]; // get the currentSum like Two Sum II
            
                if(currentSum > 0) // if currentSum > 0, reduce the right pointer to get a smaller number
                {
                    r--;
                }
                else if(currentSum < 0) // if currentSum < 0 (neg), increase the left pointer to get a larger number
                {
                    l++;
                }
                else // if currentSum = 0
                {
                    // add the numbers to the result vector, increase left pointer, decrease right pointer
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;

                    // check if there are duplicate numbers if so increase left pointer
                    while(l < r && nums[l] == nums[l-1])
                    {
                        l++;
                    }
                }
            }
       }

       return res;
    }
};
