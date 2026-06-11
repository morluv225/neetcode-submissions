class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
         count = {}  # create a char freq map
         freq = [
               [] for i in range(len(nums) + 1)
         ]  # for every element in nums, create an empty "bucket"

         for num in nums:
            count[num] = 1 + count.get(num, 0)  # get the frequency of each character
         for num, cnt in count.items(): #retrieve the key and value from count (number and frequency)
            freq[cnt].append(num) # add to the "buckets" with the key being the frequency and the value the number that associates

         res = []

         # reverse for loop aka start stop step
         # start at the last element of freq, stop once you reach 0, step by -1
         for i in range(len(freq) -1, 0, -1):
            # add the values from the freq dictionary to the final res list...
            for num in freq[i]: 
               res.append(num)
               if len(res) == k: # ....until the res size reaches k
                  return res

