class Solution {
public:
    int findMin(vector<int> &nums) {
        // Logic: A rotated array: 
        // one part is always sorted, and the other part 
        // contains the rotation and thus the minimum element
        // if the left half is sorted, the min must be in the right half or the leftmost boundary (so we check)
        // if the right half is sorted, the min must be in the left half or midpoint (so we check)

        int res = nums[0]; // set the result to be the first element
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            // if the current widnow is already sorted
            if (nums[l] < nums[r]) {
                res = min(res, nums[l]); //update result to be nums[l]
                break; // break out of this statement
            }

            //compute the midpoint
            int m = l + (r - l) / 2;
            // calculate whethere the midpoint is the minimum
            res = min(res, nums[m]);

            // if the midpoint value is >= the first value, this means that the left half is sorted
            // and the min element is not in it so we can get rid of it and search the right half
            if (nums[m] >= nums[l]) {
                l = m + 1;
            } else {
                // the right half is sorted and the min element is not in the right half
                // so we can get rid of it and search the left half
                r = m - 1;
            }
        }
        return res;
        
    }
};
