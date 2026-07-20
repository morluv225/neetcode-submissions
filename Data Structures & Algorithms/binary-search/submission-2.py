class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1 # create l, r pointers

        while l <= r:
            m = l + ((r - l) // 2) # set the midpoint

            if nums[m] > target:
                r = m -1
            elif nums[m] < target:
                l = m + 1
            else:
                return m
        return -1
