class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        charSet = set()
        l = 0
        res = 0

        for r in range(len(s)):
            while s[r] in charSet: # while s[r] is already in the set aka a duplicate
                charSet.remove(s[l]) # remove the left character from the set
                l += 1 # shrink the window size
            charSet.add(s[r]) # add the original characters to the set
            res = max(res, r - l + 1) # calculate the longest length
        return res