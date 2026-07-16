class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        pair = [(p,s) for p,s in zip(position, speed)] # creates pairs of positions and speeds
        stack = []
        pair.sort(reverse=True) # reverse the pairs order because we want to start tracking from the closest car to the farthest car

        for p,s in pair:
            stack.append((target-p)/s) # get the arrival times. time = distance/speed
            if len(stack) >= 2 and stack[-1] <= stack[-2]: # if the stack has 2 cars and the newest car's arrival time is <= the car ahead of it (the car catches up)
                stack.pop() # merge them into one fleet (aka pop off the newest car's arrival time because it adopts the other car's)
        return len(stack) # however many arrival times are left on the stack is the number of fleets