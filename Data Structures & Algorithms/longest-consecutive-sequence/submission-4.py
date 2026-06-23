class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
      numSet = set(nums) # create a set populated with all the numbers
      longest = 0 # create longst variable

      for num in numSet:
        if(num - 1) not in numSet: # if this is the start of a sequence (aka no number before it is in the set)
          length = 1 # length of the sequence is 1, because we're at the start
          while(num + length) in numSet: # while there are consecutive numbers after the starting number
            length += 1 # increase the length
          longest = max(length, longest) # determine the longest length
      return longest
        