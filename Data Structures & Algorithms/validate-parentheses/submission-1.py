class Solution:
    def isValid(self, s: str) -> bool:
        stack = [] # create the stack
        # create the dictionary that maps the correct brackets to each other 
        closeToOpen = {")":"(",
                        "]":"[",
                        "}":"{"}

        for c in s: # for every OPEN character in the string
            if c in closeToOpen: # if c is a CLOSE bracket (because our keys are all closing brackets)
                if stack and stack[-1] == closeToOpen[c]: # if the stack is not empty and the top of the stack is the corresponding OPEN bracket
                    stack.pop() # pop it off the top
                else: # if the stack is empty or the opening bracket on top does not match the closing bracket, return false
                    return False
            else: # if c is a OPEN bracket
                stack.append(c) # push it onto the stack
        return True if not stack else False # after all the chars have been processed the stack should be empty, return true if so, else false

