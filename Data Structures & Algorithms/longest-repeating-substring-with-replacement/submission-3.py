class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        l = 0
        maxFreq = 0
        count = {}
        res = 0

        for r in range(len(s)):
            count[s[r]] = 1 + count.get(s[r], 0) # get the char freq of each character
            maxFreq = max(maxFreq, count[s[r]]) # get the highest character frequency because we need it to calculate the less freq chars
            while (r - l + 1) - maxFreq > k:# if number of less frequent chars aka the numbers we want to change is greater than the numbers we're allowed to change (k)
                count[s[l]] -= 1 # remove the leftmost character
                l += 1 # shrink the window
            res = max(res, r - l + 1) # recalculate the max
        return res

        