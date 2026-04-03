class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Logic: In a rotated sorted array, one of the two halves is always sorted. 
        // We don't need to find the pivot explicitly. Instead, at each step of binary 
        // search, we determine which half is sorted and check whether the target lies
        
      int l = 0, r = nums.size() - 1;

        while (l <= r) {
            //Compute the mid point
            // if the midpoint is the target number, return immediately
            int mid = (l + r) / 2;
            if (target == nums[mid]) {
                return mid;
            }
            
            // If the left half is sorted
            if (nums[l] <= nums[mid]) {
                // Check if the target is even present in this half of the array
                // If the target is > than the midpoint, or less than the farthest left value
                // the target is NOT in this half of the array
                if (target > nums[mid] || target < nums[l]) {
                    l = mid + 1;
                } else {
                    r = mid - 1; // the target IS in the sorted left half
                }
            } else { // Otherwise, the right hald must be sorted
                // Check if the target is present in this half of the array
                // If the target is < than the midpoint, or greater than the right value
                // the target is NOT in this half of the array
                if (target < nums[mid] || target > nums[r]) {
                    r = mid - 1; 
                } else {
                    l = mid + 1; // the target IS in the sorted right half
                }
            }
        }
        return -1; // return -1 if the target isn't in either half
    }
};
