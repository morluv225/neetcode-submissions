class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        // initialize left and right pointers
        int l = 0, r = numbers.size()-1;

        // while the indices are not equal
        while(l < r)
        {
            // determine what the currentSum is 
            int currentSum = numbers[l] + numbers[r];

            /*use that sum to compare against the given target value
            the array is sorted in increasing order so the larger numbers are at the end
            thus, if currentSum > target we need to decrease the values we're using to add
            */
            if(currentSum > target)
            {
                r--;
            }

            // vice versa
            else if(currentSum < target)
            {
                l++;
            }
            else
            {
                // return the 1-based index if currentSum = target
                return {l +1, r+1};
            }
        }

        return {};
    }
};
