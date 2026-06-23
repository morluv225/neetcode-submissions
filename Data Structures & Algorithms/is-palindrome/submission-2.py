class Solution:
    def isPalindrome(self, s: str) -> bool:
        l, r = 0, len(s) - 1

        while l < r:
          while l < r and not self.isAlphaNum(s[l]): # while the left character is not an alphanum move it forward
            l += 1
          while r > l and not self.isAlphaNum(s[r]): # while the right character is not an alphanum move it backward
            r -= 1
          if s[l].lower() != s[r].lower(): # if the valid alphanum characters don't match, return false
            return False
          l, r = l + 1, r - 1 # continue to move the pointers inwards
        return True

    # check if the character is an alphanum  
    def isAlphaNum(self, c):
      return(ord('A') <= ord(c) <= ord('Z') or
              ord('a') <= ord(c) <= ord('z') or
              ord('0') <= ord(c) <= ord('9'))
              