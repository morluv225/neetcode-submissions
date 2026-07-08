class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        l, r = 0, 1 # set pointers, l is the buy day, r is the sell day
        maxP = 0

        while r < len(prices):
            if prices[l] < prices[r]: # if the price to buy is cheaper than the price to sell
                 currMax = prices[r] - prices[l] # keep track of the current max
                 maxP = max(maxP, currMax) # calculate the total max
            else: # if the amount to sell is cheaper than the amount to buy
                l = r # move the left pointer up to the right pointer position because a cheaper buying price is always better
            r += 1 # increment r to the next point
        return maxP

