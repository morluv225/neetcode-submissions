class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int left = 0;
        int right = numbers.size() -1;
        int currentSum = 0;
        
        while(left < right)
        {
            currentSum = numbers[left] + numbers[right];

            if(currentSum == target)
            {
                return {left + 1, right + 1};
            }
            else if(currentSum > target)
            {
                right--;
            }
            else
            {
                left++;
            }
        }

        return {};
    }
};
