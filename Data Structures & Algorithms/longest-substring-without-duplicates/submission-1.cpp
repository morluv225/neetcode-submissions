class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_set<char> seen;
        int left = 0;
        int maxLength = 0;

        for(int right = 0; right < s.length(); right++)
        {
            while(seen.count(s.at(right)))
            {
                seen.erase(s.at(left));
                left++;
            }

            seen.insert(s.at(right));
            maxLength = max(maxLength, right-left+1);
        }

        return maxLength;
    }
};
