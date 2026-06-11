class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
      res = defaultdict(list) # default dict will automatically create an empty list for any non-existent key
      for s in strs:
         count = [0] * 26 # create a 26 char long array to contain the char freq of each string
         for c in s:
            count[ord(c) - ord('a')] += 1 # increment the char freq based on the unicode value
         # convert the character array for each string into an immutable tuple to use as a key
         # append the correlating string(s) as the value of this key
         res[tuple(count)].append(s)
      return list(res.values()) # return the list of strings
        