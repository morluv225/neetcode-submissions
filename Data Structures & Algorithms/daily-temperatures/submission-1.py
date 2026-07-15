class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        res = [0] * len(temperatures) # create an array filled with 0s for each day
        stack = []

        # need to get the index and temperature pairs
        for i, t in enumerate(temperatures):
            while stack and t > stack[-1][0]:
                stackT, stackId = stack.pop() # get the cooler temperature and index off the stack
                res[stackId] = i - stackId # compute the number of "days" between the warmer temps index and the cooler temps index and store it in the result array
            stack.append((t,i)) # append the temp and index of each day
        return res
